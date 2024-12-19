PORTNAME=	libsml
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	mail+freebsd@gerritbeine.de
COMMENT=	Implementation in C of the Smart Message Language (SML) protocol
WWW=		https://github.com/volkszaehler/libsml

LICENSE=	GPLv3

LIB_DEPENDS=	libuuid.so:misc/libuuid

USES=		dos2unix gmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
DOS2UNIX_FILES=	test/unity/unity.c
GH_ACCOUNT=	volkszaehler
GH_TAGNAME=	2a8445b

ALL_TARGET=	all
CFLAGS+=	-I ${PREFIX}/include

post-patch:
	${REINPLACE_CMD} -e "s|-luuid|-luuid -L ${PREFIX}/lib|" ${WRKSRC}/examples/Makefile
	${REINPLACE_CMD} -e "s|-luuid|-luuid -L ${PREFIX}/lib|" ${WRKSRC}/test/Makefile
	${REINPLACE_CMD} -e "s|prefix = /usr/local|prefix = ${STAGEDIR}${PREFIX}|" ${WRKSRC}/examples/Makefile
	${REINPLACE_CMD} -e "s|prefix = /usr/local|prefix = ${STAGEDIR}${PREFIX}|" ${WRKSRC}/sml/Makefile

.include <bsd.port.mk>
