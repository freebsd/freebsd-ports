# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vanitygen
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	finance

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone vanity address generator for bitcoin

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	samr7
GH_TAGNAME=	cd1a728

USES=		gmake ssl
ALL_TARGET=	most

PLIST_FILES=	bin/keyconv bin/vanitygen

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	field has incomplete type 'BIGNUM' (aka 'struct bignum_st')
BROKEN_FreeBSD_13=	field has incomplete type 'BIGNUM' (aka 'struct bignum_st')
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpcre|$$(shell pcre-config --libs)| ; \
		 s|-lpthread|-pthread $$(LDFLAGS)| ; \
		 s|^\(CFLAGS\).*|\1+=$$(shell pcre-config --cflags)|' \
		${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} keyconv vanitygen \
		${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.post.mk>
