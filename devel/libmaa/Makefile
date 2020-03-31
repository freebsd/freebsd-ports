# Created by: chinsan
# $FreeBSD$

PORTNAME=	libmaa
PORTVERSION=	1.4.5
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides a few data structures and helpful functions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

BUILD_DEPENDS=	mk-configure>=0.29.1:devel/mk-configure

MAKE_ARGS=	DOCDIR=${DOCSDIR}
MAKE_CMD=	mkcmake
USE_LDCONFIG=	yes

GH_ACCOUNT=	cheusov
USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^FILES *=/ s|LICENSE||' ${WRKSRC}/doc/Makefile
	@${REINPLACE_CMD} -e '/^#SHLIB_TEENY *=/ s|#||' ${WRKSRC}/maa/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmaa.so

.include <bsd.port.mk>
