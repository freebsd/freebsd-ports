# New ports collection makefile for:	MIT-Scheme
# Date created:		Mar 26 1995
# Whom:			jmacd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mit-scheme
PORTVERSION=	7.6.0
CATEGORIES=	lang
MASTER_SITES=	ftp.swiss.ai.mit.edu/pub/mit-scheme/7.6/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION} OLD/${PORTVERSION}
DISTNAME=	scheme-${PORTVERSION}-ix86-freebsd

MAINTAINER=	olgeni@FreeBSD.org

LIB_DEPENDS=	c.3:${PORTSDIR}/misc/compat3x

ONLY_FOR_ARCHS=	i386
USE_XLIB=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/scheme ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bchscheme ${PREFIX}/bin
	cd ${WRKSRC}/lib && pax -rw mit-scheme ${PREFIX}/lib
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/mit-scheme

.include <bsd.port.mk>
