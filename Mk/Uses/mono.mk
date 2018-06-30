# $FreeBSD$
#
# mono (c#) support
#
# Feature:	mono
# Usage:	USES=mono:ARGS
# Valid ARGS:	nuget
#
# MAINTAINER=	mono@FreeBSD.org
#
# Arguments:
#
# nuget		Specifies that the port uses nuget packages.
#
#		EXTRACT_ONLY is conditionally overridden to exclude all
#		files with a '.nupkg' extension.
#
# Targets:
#
# makenuget	This target will output the NUGET_DEPENDS based on the
#		port's packages.config file.
#
# makenupkg	This target will create nupkg-${NAME} files based on the
# 		port's downloaded packages in ${NUGET_PACKAGEDIR}
#
# Variables overrideable by the port:
#
# NUGET_PACKAGEDIR	The directory in which the port expects the
#			nuget packages to be available
#			default: ${WRKSRC}/packages
#
# NUGET_LAYOUT		The directory layout of ${NUGET_PACKAGEDIR}:
# 				legacy:
# 					${NAME}
# 					${NAME}.${VERSION}
# 					${NAME.tl}/${VERSION}
# 				flat:
# 					${NAME}
# 					${NAME:tl}
# 				dotnet:
# 					${NAME:tl}/${VERSION}
# 			default: legacy
#
# NUGET_FEEDS		A list of nuget feed names
#			default: NUGET
#
# ${NAME}_URL:		The base URL for the feed ${NAME}
#			defaults:
#				NUGET_URL=https://www.nuget.org/api/v2/
#				${NAME}_URL=https://dotnet.myget.org/F/${NAME:tl:S/_/-/g}/api/v2/
#
# ${NAME}_FILE:		The file containing a list of nuget packages from
# 			feed ${NAME} in the format:
# 				${name}=${version}
# 			default: ${PKGDIR}/nupkg-${NAME:tl}
#
# ${NAME}_DEPENDS:	The list of nuget packages from feed ${NAME} in the
#			format:
#				${name}=${version}
#			defaults:
#				NUGET_DEPENDS=${PAKET_DEPENDS}
#
# PAKET_PACKAGEDIR	The directory in which the port expects the
# 			nuget packages (managed by paket) to be available
#
# PAKET_DEPENDS		The list of nuget packages from a nuget feed.  The
# 			version used needs to be resolved (unlike how paket
# 			works).  The format is:
# 				${name}=${version}

.if !defined(_INCLUDE_USES_MONO_MK)
_INCLUDE_USES_MONO_MK=	yes

.if !empty(mono_ARGS:Nnuget)
IGNORE=	USES=mono only supports an optional nuget argument
.endif

# Set the location of the .wapi directory so we write to a location we
# can always assume to be writable.
MONO_SHARED_DIR=	${WRKDIR}
CONFIGURE_ENV+=		MONO_SHARED_DIR="${MONO_SHARED_DIR}"
MAKE_ENV+=		MONO_SHARED_DIR="${MONO_SHARED_DIR}" TZ=UTC
BUILD_DEPENDS+=		mono:lang/mono
RUN_DEPENDS+=		mono:lang/mono

# Set the location that webaps served by XSP should use.
XSP_DOCROOT=		${PREFIX}/www/xsp

# gac utilities
GACUTIL=${LOCALBASE}/bin/gacutil /root ${PREFIX}/lib/ /gacdir ${PREFIX}/lib
GACUTIL_INSTALL=${GACUTIL} /i
GACUTIL_INSTALL_PACKAGE=${GACUTIL} /i /package 1.0 /package 2.0

.if ${mono_ARGS:Mnuget}
MAKE_ENV+=	NUGET_PACKAGES=${NUGET_PACKAGEDIR}

# TODO: add nuget as a Port, use it for makenupkg
NUGET_EXE?=	${WRKDIR}/nuget.exe
NUGET_LATEST_URL?=	https://dist.nuget.org/win-x86-commandline/latest/nuget.exe

_NUGET_PACKAGEDIR=	${WRKDIR}/.nuget/packages
NUGET_PACKAGEDIR?=	${WRKSRC}/packages
NUGET_LAYOUT?=		legacy
NUGET_FEEDS?=		NUGET
NUGET_URL?=		https://www.nuget.org/api/v2/

PAKET_PACKAGEDIR?=
PAKET_DEPENDS?=
NUGET_DEPENDS?=		${PAKET_DEPENDS}

. for feed in ${NUGET_FEEDS}
${feed}_DEPENDS?=
${feed}_FILE?=		${PKGDIR}/nupkg-${feed:tl}
${feed}_URL?=		https://dotnet.myget.org/F/${feed:tl:S/_/-/g}/api/v2/
.  if exists(${${feed}_FILE})
${feed}_EXTRA!=		${CAT} ${${feed}_FILE}
.  else
${feed}_EXTRA=
.  endif
.  for depend in ${${feed}_DEPENDS} ${${feed}_EXTRA}
.   if empty(_NUGET_DEPENDS:M${depend})
id=		${depend:C/=.*$//}
version=	${depend:C/^.*=//}
group=		nuget_${depend:S/.//g:S/-//g:S/=//g}
nupkg=		${id:tl}.${version}.nupkg
DISTFILES_${group}:=	${nupkg}:${group}
MASTER_SITES_${group}:=	${${feed}_URL}package/${id}/${version}?dummy=/:${group}
NUGET_NUPKGS_${group}:=	${nupkg}:${depend}
NUPKGS_${id}:=	${NUPKGS_${id}} ${version}

DISTFILES+=	${DISTFILES_nuget_${depend:S/.//g:S/-//g:S/=//g}}
MASTER_SITES+=	${MASTER_SITES_nuget_${depend:S/.//g:S/-//g:S/=//g}}
NUGET_NUPKGS+=	${NUGET_NUPKGS_nuget_${depend:S/.//g:S/-//g:S/=//g}}
_NUGET_DEPENDS+=	${depend}
.   endif
.  endfor
. endfor

EXTRACT_ONLY?=	${_DISTFILES:N*.nupkg}

_USES_extract+=	600:nuget-extract
nuget-extract:
	@${MKDIR} ${_NUGET_PACKAGEDIR} ${PAKET_PACKAGEDIR}
. for nupkg in ${NUGET_NUPKGS}
	@${MKDIR} ${_NUGET_PACKAGEDIR}/${nupkg:tl:C/^.*://:S|=|/|}
	@tar -xf ${DISTDIR}/${nupkg:C/:.*$//} -C ${_NUGET_PACKAGEDIR}/${nupkg:tl:C/^.*://:S|=|/|} \
		-s/%2B/\+/g -s/%2B/\+/g -s/%2B/\+/g \
		--exclude '\[Content_Types\].xml' \
		--exclude package/ \
		--exclude _rels/
	@${MV} ${_NUGET_PACKAGEDIR}/${nupkg:tl:C/^.*://:S|=|/|}/${nupkg:C/^.*://:C/=.*//}.nuspec \
		${_NUGET_PACKAGEDIR}/${nupkg:tl:C/^.*://:S|=|/|}/${nupkg:tl:C/^.*://:C/=.*//}.nuspec
	@${CP} ${DISTDIR}/${nupkg:C/:.*$//} ${_NUGET_PACKAGEDIR}/${nupkg:tl:C/^.*://:S|=|/|}/${nupkg:tl:C/^.*://:S/=/./}.nupkg
	@openssl dgst -sha512 -binary ${DISTDIR}/${nupkg:C/:.*$//} | openssl enc -base64 | ${TR} -d "\n" \
		> ${_NUGET_PACKAGEDIR}/${nupkg:tl:C/^.*://:S|=|/|}/${nupkg:tl:C/^.*://:S/=/./}.nupkg.sha512
.  if ${NUGET_LAYOUT} == legacy
	@${CP} -a ${_NUGET_PACKAGEDIR}/${nupkg:tl:C/^.*://:S|=|/|}/ ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|.|}/
	@${CP} -a ${_NUGET_PACKAGEDIR}/${nupkg:tl:C/^.*://:S|=|/|}/ ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:C|=.*||}/
.   if ${nupkg} != ${nupkg:tl}
	@(cd ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:C|=.*||}; \
		${MV} ${nupkg:tl:C/^.*://:C/=.*//}.nuspec ${nupkg:C/^.*://:C/=.*//}.nuspec; \
		${MV} ${nupkg:tl:C/^.*://:S/=/./}.nupkg ${nupkg:C/^.*://:S/=/./}.nupkg; \
		${MV} ${nupkg:tl:C/^.*://:S/=/./}.nupkg.sha512 ${nupkg:C/^.*://:S/=/./}.nupkg.sha512)
	@(cd ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|.|}; \
		${MV} ${nupkg:tl:C/^.*://:C/=.*//}.nuspec ${nupkg:C/^.*://:C/=.*//}.nuspec; \
		${MV} ${nupkg:tl:C/^.*://:S/=/./}.nupkg ${nupkg:C/^.*://:S/=/./}.nupkg; \
		${MV} ${nupkg:tl:C/^.*://:S/=/./}.nupkg.sha512 ${nupkg:C/^.*://:S/=/./}.nupkg.sha512)
.   endif
.  elif ${NUGET_LAYOUT} == flat
	@${CP} -a ${_NUGET_PACKAGEDIR}/${nupkg:tl:C/^.*://:S|=|/|}/ ${_NUGET_PACKAGEDIR}/${nupkg:tl:C/^.*://:C|=.*||}/
	@${RM} -r ${_NUGET_PACKAGEDIR}/${nupkg:tl:C/^.*://:S|=|/|}
.   if ${nupkg} != ${nupkg:tl}
	@${CP} -a ${_NUGET_PACKAGEDIR}/${nupkg:tl:C/^.*://:C|=.*||}/ ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:C|=.*||}/
	@(cd ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:C|=.*||}; \
		${MV} ${nupkg:tl:C/^.*://:C/=.*//}.nuspec ${nupkg:C/^.*://:C/=.*//}.nuspec; \
		${MV} ${nupkg:tl:C/^.*://:S/=/./}.nupkg ${nupkg:C/^.*://:S/=/./}.nupkg; \
		${MV} ${nupkg:tl:C/^.*://:S/=/./}.nupkg.sha512 ${nupkg:C/^.*://:S/=/./}.nupkg.sha512)
.   endif
.  endif
. endfor
	@${RLN} ${_NUGET_PACKAGEDIR} ${NUGET_PACKAGEDIR}
	@${TOUCH} ${WRKDIR}/.nuget-sentinal

_USES_extract+=	601:paket-extract
paket-extract:
. for nupkg in ${PAKET_DEPENDS}
	@${RLN} ${_NUGET_PACKAGEDIR}/${nupkg:tl:S|=|/|} ${PAKET_PACKAGEDIR}/${nupkg:C/=.*//}
	@(cd ${_NUGET_PACKAGEDIR}/${nupkg:tl:C/^.*://:S|=|/|}; \
		${CP} ${nupkg:tl:C/^.*://:C/=.*//}.nuspec ${nupkg:C/^.*://:C/=.*//}.nuspec; \
		${CP} ${nupkg:tl:C/^.*://:S/=/./}.nupkg ${nupkg:C/^.*://:S/=/./}.nupkg; \
		${CP} ${nupkg:tl:C/^.*://:S/=/./}.nupkg.sha512 ${nupkg:C/^.*://:S/=/./}.nupkg.sha512)
. endfor
.endif

makenuget: patch
	@${FIND} ${WRKSRC} -name packages.config | \
		${XARGS} ${SED} -nE 's|.*<package id="([^"]+)" version="([^"]+)"[^/]*/>.*|\1=\2|gp' | \
		${SORT} -u | \
		${SED} \
			-e '1s|^|NUGET_DEPENDS=	|' \
			-e '2,$$s|^|		|g' \
			-e '$$!s|$$| \\|g'

makenupkg:
	@[ -f ${NUGET_EXE} ] || fetch -o ${NUGET_EXE} ${NUGET_LATEST_URL}
.for feed in ${NUGET_FEEDS}
	@[ -f ${WRKDIR}/.nupkg-${feed:tl} -o ${feed} = NUGET ] || mono ${NUGET_EXE} list -AllVersions -IncludeDelisted -PreRelease -Source ${${feed}_URL} | ${SED} 's/ /=/g' > ${WRKDIR}/.nupkg-${feed:tl}
	@${RM} ${WRKDIR}/nupkg-${feed:tl}
.endfor
	@for nuspec in `${FIND} ${_NUGET_PACKAGEDIR} -name '*.nuspec'`; do \
		name="`${SED} -nE 's|.*<id>(.*)</id>.*|\1|p' $$nuspec`"; \
		version="`${SED} -nE 's|.*<version>(.*)</version>.*|\1|p' $$nuspec`"; \
		${ECHO} $$name=$$version; \
	done | ${SORT} -u > ${WRKDIR}/.nupkgs
	@${CAT} ${WRKDIR}/.nupkgs | while read nupkg; do \
		default=no; \
		for feed in ${NUGET_FEEDS:tl}; do \
			if [ $$feed = nuget ]; then \
				default=yes; \
			elif ${GREP} -q "^$$nupkg\$$" ${WRKDIR}/.nupkg-$$feed; then \
				${ECHO} $$nupkg >> ${WRKDIR}/nupkg-$$feed; \
				default=na; \
				break; \
			fi; \
		done; \
		if [ $$default = yes ]; then \
			${ECHO} $$nupkg >> ${WRKDIR}/nupkg-nuget; \
		fi; \
	done
.endif
