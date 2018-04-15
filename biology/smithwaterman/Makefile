# $FreeBSD$

PORTNAME=	smithwaterman
DISTVERSION=	g20160702
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Smith-waterman-gotoh alignment algorithm

LICENSE=	GPLv2

USES=		gmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TAGNAME=	2610e259611ae4cde8f03c72499d28f03f6d38a7

MAKEFILE=	${FILESDIR}/Makefile
INSTALL_TARGET=	install-strip

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libsw.so.1 \
		${STAGEDIR}${PREFIX}/lib/libsw.so

.include <bsd.port.mk>
