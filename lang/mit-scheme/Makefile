# New ports collection makefile for:	MIT-Scheme
# Date created:		Mar 26 1995
# Whom:			jmacd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mit-scheme
PORTVERSION=	7.5.10
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.swiss.ai.mit.edu/pub/scheme-7.5/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	scheme-${PORTVERSION}-ix86-freebsd

MAINTAINER= 	ports@FreeBSD.org

ONLY_FOR_ARCHS=	i386

USE_XLIB=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/scheme ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bchscheme ${PREFIX}/bin
	${TAR} -C ${WRKSRC}/lib -cf - mit-scheme | \
		${TAR} -C ${PREFIX}/lib --unlink -xf -
	find ${PREFIX}/lib/mit-scheme | xargs ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	find ${PREFIX}/lib/mit-scheme -type f | xargs ${CHMOD} ${SHAREMODE}

.include <bsd.port.mk>
