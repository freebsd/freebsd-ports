# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vanitygen
PORTVERSION=	0.22
CATEGORIES=	finance

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone vanity address generator for bitcoin

LICENSE=	AGPLv3

LIB_DEPENDS=	libpcre.so:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	samr7
GH_TAGNAME=	cd1a728

USES=		gmake
USE_OPENSSL=	yes
ALL_TARGET=	most

PLIST_FILES=	bin/keyconv bin/vanitygen

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpcre|$$(shell pcre-config --libs)| ; \
		 s|-lpthread|-pthread $$(LDFLAGS)| ; \
		 s|^\(CFLAGS\).*|\1+=$$(shell pcre-config --cflags)|' \
		${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} keyconv vanitygen \
		${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
