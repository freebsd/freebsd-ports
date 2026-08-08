PORTNAME=	pkgconf
DISTVERSION=	3.0.5
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/ \
		https://distfiles.ariadne.space/${PORTNAME}/

# NOTE: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Utility to help to configure compiler and linker flags
WWW=		https://gitea.treehouse.systems/ariadne/${PORTNAME}

LICENSE=	ISCL

USES=		cpe meson:muon ninja:samurai tar:xz
USE_LDCONFIG=	yes

# eliminate PKG_CONFIG_LIBDIR from test env
TEST_ENV=
ALL_TARGET=
MESON_ARGS=	--default-library both \
		-Dwith-pkg-config-dir=${PREFIX}/libdata/pkgconfig:/usr/libdata/pkgconfig:${PREFIX}/share/pkgconfig \
		-Dwith-system-libdir=/usr/lib \
		-Dwith-system-includedir=/usr/include

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bomtool
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pccritic
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pkgconf
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spdxtool
	${RLN} ${STAGEDIR}${PREFIX}/bin/pkgconf ${STAGEDIR}${PREFIX}/bin/pkg-config

do-test:
	(cd ${TEST_WRKSRC} && ${SETENV} ${CONFIGURE_CMD} test -v -d dots)

.include <bsd.port.mk>
