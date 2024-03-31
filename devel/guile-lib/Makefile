PORTNAME=	guile-lib
PORTVERSION=	0.2.8
CATEGORIES=	devel scheme
MASTER_SITES=	SAVANNAH
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Repository of useful code written in Guile Scheme
WWW=		https://www.nongnu.org/guile-lib/

LICENSE=	LGPL3 GPLv3
LICENSE_COMB=	multi

USES=		gmake guile:2.2,3.0,flavors,build,run pkgconfig

CONFIGURE_ARGS+=--with-guile-site
GNU_CONFIGURE=	yes
INFO_PATH=	${GUILE_INFO_PATH}
TEST_TARGET=	check

INFO=		guile-library

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${GUILE_PKGCONFIG_DIR}
	${MV} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/guile-lib-1.0.pc ${STAGEDIR}${PREFIX}/${GUILE_PKGCONFIG_DIR}/

.include <bsd.port.mk>
