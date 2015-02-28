# Created by: mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	raproxy
PORTVERSION=	3.0b1
PORTREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	http://docs.real.com/docs/proxy/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Progressive Networks RealAudio Proxy Kit 3.0 beta 1

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-03-28

ALL_TARGET=	raproxy
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

RESTRICTED=	License allows only use in a firewall or with RA products.

PLIST_FILES=	libexec/raproxy man/man8/raproxy.8.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/raproxy ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/raproxy.man ${STAGEDIR}${PREFIX}/man/man8/raproxy.8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/*.pdf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
