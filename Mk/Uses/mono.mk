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
# nuget		Specifies that the port uses nuget packages.  The
#		variables NUGET_DEPENDS needs to be set with the names,
#		versions and optionally the port origin of the nuget
#		packages in the format:
#			${name}=${version}(:${PKGORIGIN})
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
NUGET_PACKAGEDIR?=	${WRKSRC}/packages

.  for depend in ${NUGET_DEPENDS}
id=		${depend:C/=.*$//}
version=	${depend:C/^.*=//}
group=		nuget_${id:S/.//g:S/-//g}
nupkg=		${id:tl}.${version}.nupkg
DISTFILES_${group}:=	${nupkg}:${group}
MASTER_SITES_${group}:=	https://www.nuget.org/api/v2/package/${id}/${version}?dummy=/:${group}
NUGET_NUPKGS_${group}:=	${nupkg}:${depend}

DISTFILES+=	${DISTFILES_nuget_${depend:C/=.*$//:S/.//g:S/-//g}}
MASTER_SITES+=	${MASTER_SITES_nuget_${depend:C/=.*$//:S/.//g:S/-//g}}
NUGET_NUPKGS+=	${NUGET_NUPKGS_nuget_${depend:C/=.*$//:S/.//g:S/-//g}}
.  endfor

EXTRACT_ONLY?=	${_DISTFILES:N*.nupkg}

_USES_extract+=	600:nuget-extract
nuget-extract:
.  for nupkg in ${NUGET_NUPKGS}
	@${MKDIR} ${NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S/=/./}
	@${RM} -f ${NUGET_PACKAGEDIR}/${nupkg:C/^.*://:C/=.*//}
	@${LN} -s ${NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S/=/./} ${NUGET_PACKAGEDIR}/${nupkg:C/^.*://:C/=.*//}
	@tar -xf ${DISTDIR}/${nupkg:C/:.*$//} -C ${NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S/=/./} \
		-s/%2B/\+/g -s/%2B/\+/g -s/%2B/\+/g \
		--exclude '\[Content_Types\].xml' \
		--exclude package/ \
		--exclude _rels/
	@${CP} ${DISTDIR}/${nupkg:C/:.*$//} ${NUGET_PACKAGEDIR}/${nupkg:C/^.*://:S/=/./}/${nupkg:C/^.*://:S/=/./}.nupkg
.  endfor
.endif

makenuget: patch
	@${FIND} ${WRKSRC} -name packages.config | \
		${XARGS} ${SED} -nE 's|.*<package id="([^"]+)" version="([^"]+)"[^/]*/>.*|\1=\2|gp' | \
		${SORT} -u | \
		${SED} \
			-e '1s|^|NUGET_DEPENDS=	|' \
			-e '2,$$s|^|		|g' \
			-e '$$!s|$$| \\|g'

.endif

