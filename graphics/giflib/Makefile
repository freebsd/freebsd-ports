PORTNAME=	giflib
PORTVERSION=	6.1.3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/giflib-6.x

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Tools and library routines for working with GIF images
WWW=		https://sourceforge.net/projects/giflib/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	ghead:sysutils/coreutils

USES=		cpe gmake
CPE_VENDOR=	giflib_project
USE_LDCONFIG=	yes

MAKE_ARGS=	CC=${CC} \
		LDFLAGS="${LDFLAGS}" \
		OFLAGS="${CFLAGS}" \
		PREFIX="${PREFIX}"
TEST_TARGET=	check

CFLAGS+=	-DHAVE_REALLOCARRAY

CONFLICTS_INSTALL=	giftool

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} --strip-unneeded ${STAGEDIR}${PREFIX}/lib/libgif.so.7.2.0

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! ( -name Makefile -o -name *\.[17] -o -name *\.xml )"
	${MV} ${STAGEDIR}${DOCSDIR}/index.html.in ${STAGEDIR}${DOCSDIR}/index.html

.include <bsd.port.mk>
