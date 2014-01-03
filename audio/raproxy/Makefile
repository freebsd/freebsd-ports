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

ALL_TARGET=	raproxy
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

RESTRICTED=	License allows only use in a firewall or with RA products.

NO_STAGE=	yes
PLIST_FILES=	libexec/raproxy
PORTDOCS=	*
MAN8=		raproxy.8

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/raproxy ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/raproxy.man ${PREFIX}/man/man8/raproxy.8

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${PREFIX}/share/doc/raproxy
	@${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/*.pdf \
		${PREFIX}/share/doc/raproxy
.endif

.include <bsd.port.mk>
