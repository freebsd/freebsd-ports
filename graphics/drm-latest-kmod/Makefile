PORTNAME=	drm-latest-kmod
DISTVERSION=	${DRM_KMOD_DISTVERSION}
CATEGORIES=	graphics kld

.include "Makefile.version"

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Direct Rendering Manager (DRM) GPU drivers
WWW=		https://github.com/freebsd/drm-kmod/

LICENSE=	BSD2CLAUSE MIT GPLv2
LICENSE_COMB=	multi

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	the new KMS components are only supported on amd64

CONFLICTS_INSTALL=	drm-515-kmod \
			drm-61-kmod \
			drm-66-kmod \
			drm-612-kmod

USES=		kmod uidfix compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	drm-kmod
GH_TAGNAME=	${DRM_KMOD_GH_TAGNAME}

.include <bsd.port.options.mk>

SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} OPSYS=${OPSYS} OSREL=${OSREL}

.if ${OPSYS} != FreeBSD
IGNORE=         not supported on anything but FreeBSD (missing linuxkpi functionality)
.elif ${OSVERSION} < 1500509
IGNORE=         not supported on FreeBSD < 1500509, no kernel support
.elif 1600000 <= ${OSVERSION} && ${OSVERSION} < 1600018
IGNORE=         not supported on FreeBSD 16 before 1600018, no kernel support
.endif

MAKE_ENV+=	MAKEOBJDIRPREFIX=${WRKSRC}/obj

pre-build:
		${MKDIR} ${WRKSRC}/obj
		(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} obj)

.include <bsd.port.mk>
