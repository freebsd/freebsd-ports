# New ports collection makefile for:	raproxy
# Date created:		January 24, 1999
# Whom:		mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	raproxy
PORTVERSION=	3.0b1
PORTREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	http://docs.real.com/proxykit/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@freebsd.org

# Get it through http://www.real.com/firewall/fwdload/index.html
# if the master site does not exists somehow.
WRKSRC=		${WRKDIR}/raproxy
ALL_TARGET=	raproxy

RESTRICTED=	License allows only use in a firewall or with RA products.

MAN8=		raproxy.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/raproxy ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/raproxy.man ${PREFIX}/man/man8/raproxy.8

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/raproxy
	@${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/*.pdf \
		${PREFIX}/share/doc/raproxy
.endif

.include <bsd.port.mk>
