PORTNAME=	muon
DISTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	https://muon.build/releases/v${DISTVERSION}/ \
		https://muon.build/releases/v${DISTVERSION}/docs/:docs
DISTFILES=	${PORTNAME}-v${DISTVERSION}${EXTRACT_SUFX} \
		man.tar.gz:docs
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Build system compatible with meson
WWW=		https://muon.build/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

USES=		ninja:samurai pkgconfig:both

WRKSRC=		${WRKDIR}/${PORTNAME}-v${DISTVERSION}
BUILD_WRKSRC=	${WRKSRC}/_build
INSTALL_WRKSRC=	${WRKSRC}/_build

ALL_TARGET=
PLIST_FILES=	bin/muon \
		share/man/man1/muon.1.gz \
		share/man/man5/meson.build.5.gz

CFLAGS+=	-D__XSI_VISIBLE=1
CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"

do-configure:
	@(cd ${WRKSRC} && \
		${SETENVI} ${CONFIGURE_ENV} ${SH} bootstrap.sh . && \
		${SETENVI} ${CONFIGURE_ENV} ./muon-bootstrap setup \
			-Dlibcurl=disabled \
			-Dlibarchive=disabled \
			-Dtracy=disabled \
			-Dmeson-tests=disabled \
			-Dmeson-docs=disabled \
			-Dlibpkgconf=enabled \
			${BUILD_WRKSRC})

do-install:
	@(${SETENVI} ${MAKE_ENV} ${BUILD_WRKSRC}/muon -C ${BUILD_WRKSRC} install)
	@${INSTALL_MAN} ${WRKDIR}/man/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${INSTALL_MAN} ${WRKDIR}/man/*.5 ${STAGEDIR}${PREFIX}/share/man/man5

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
