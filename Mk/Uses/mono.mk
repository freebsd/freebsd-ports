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
# Variables overrideable by the port:
#
# NUGET_PACKAGEDIR	The directory in which the port expects the
#			nuget packages to be available
#			default: ${WRKSRC}/packages
#
# NUGET_FEEDS		A list of nuget feed names
#			default: NUGET
#
# ${NAME}_URL:		The base URL for the feed ${NAME}
#			defaults:
#				NUGET_URL=https://www.nuget.org/api/v2/
#
# ${NAME}_FILE:		The file containing a list of nuget packages from
# 			feed ${NAME} in the format:
# 				${name}=${version}
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
NUGET_EXE?=	${WRKSRC}/external/nuget-binary/nuget.exe

_NUGET_PACKAGEDIR=	${WRKDIR}/.nuget/packages
NUGET_PACKAGEDIR?=	${WRKSRC}/packages
NUGET_FEEDS?=		NUGET
NUGET_URL?=		https://www.nuget.org/api/v2/

PAKET_PACKAGEDIR?=
PAKET_DEPENDS?=
NUGET_DEPENDS?=		${PAKET_DEPENDS}

. for feed in ${NUGET_FEEDS}
${feed}_DEPENDS?=
${feed}_FILE?=		${PKGDIR}/nupkg-${feed:tl}
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
.  if !empty(NUPKGS_${nupkg:C/^.*://:C/=.*//}:[2])
	@${MKDIR} ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|/|}
.  else
	@${MKDIR} ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:C/=.*//}
	@${LN} -s ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:C/=.*//} ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|/|}
.  endif
	@tar -xf ${DISTDIR}/${nupkg:C/:.*$//} -C ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|/|} \
		-s/%2B/\+/g -s/%2B/\+/g -s/%2B/\+/g \
		--exclude '\[Content_Types\].xml' \
		--exclude package/ \
		--exclude _rels/
	@${CP} ${DISTDIR}/${nupkg:C/:.*$//} ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|/|}/${nupkg:C/^.*://:S/=/./}.nupkg
	@openssl dgst -sha512 -binary ${DISTDIR}/${nupkg:C/:.*$//} | openssl enc -base64 | ${TR} -d "\n" \
		> ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|/|}/${nupkg:C/^.*://:S/=/./}.nupkg.sha512
	@${LN} -s ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|/|} ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S/=/./}
.  if ${nupkg:C/^.*://:tl} != ${nupkg:C/^.*://}
	@${LN} -s ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|/|}/${nupkg:C/^.*://:C/=.*$//}.nuspec ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|/|}/${nupkg:C/^.*://:C/=.*$//:tl}.nuspec
	@${LN} -s ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|/|}/${nupkg:C/^.*://:S/=/./}.nupkg ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|/|}/${nupkg:C/^.*://:S/=/./:tl}.nupkg
	@${LN} -s ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|/|}/${nupkg:C/^.*://:S/=/./}.nupkg.sha512 ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|/|}/${nupkg:C/^.*://:S/=/./:tl}.nupkg.sha512
	@${LN} -s ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S|=|/|} ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S/=/./:tl}
	@[ -e ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:C/=.*$//:tl} ] || ${LN} -s ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:C/=.*$//} ${_NUGET_PACKAGEDIR}/${nupkg:C/^.*://:C/=.*$//:tl}
.  endif
. endfor
	@${LN} -s ${_NUGET_PACKAGEDIR} ${NUGET_PACKAGEDIR}
	@${TOUCH} ${WRKDIR}/.nuget-sentinal

_USES_extract+=	601:paket-extract
paket-extract:
. for nupkg in ${PAKET_DEPENDS}
	@${LN} -s ${_NUGET_PACKAGEDIR}/${nupkg:S|=|/|} ${PAKET_PACKAGEDIR}/${nupkg:C/=.*$//}
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
.for feed in ${NUGET_FEEDS}
	@[ -f ${WRKDIR}/.nupkg-${feed:tl} ] || mono ${NUGET_EXE} list -IncludeDelisted -PreRelease -Source ${${feed}_URL} | ${SED} 's/ .*//g' > ${WRKDIR}/.nupkg-${feed:tl}
	@${RM} ${WRKDIR}/nupkg-${feed:tl}
.endfor
	@for nupkg in `${FIND} ${_NUGET_PACKAGEDIR} -name '*.sha512' | ${SED} 's/\.sha512//g'`; \
	do \
		name="`tar -tf $${nupkg} | ${GREP} nuspec | ${SED} 's/.nuspec//g'`"; \
		version="`${BASENAME} $$(${DIRNAME} $$nupkg)`"; \
		${ECHO} "$$name=$${version#$$name.}"; \
	done | ${SORT} -u > ${WRKDIR}/.nupkgs
	@${CAT} ${WRKDIR}/.nupkgs | while read nupkg; do \
		for feed in ${NUGET_FEEDS:tl}; do \
			if ${GREP} -q "^$${nupkg%%=*}\$$" ${WRKDIR}/.nupkg-$$feed; then \
				${ECHO} $$nupkg >> ${WRKDIR}/nupkg-$$feed; \
				break; \
			fi; \
		done; \
	done
.endif
