# New ports collection makefile for:	ScrollZ
# Date created:		10 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	scrollz
PORTVERSION=	1.8k
CATEGORIES=	irc
MASTER_SITES=	http://www.scrollz.com/Bins/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd-4.2
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org

EXTRACT_CMD=	gunzip
EXTRACT_BEFORE_ARGS=	-c
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/scrollz
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scrollz ${PREFIX}/bin/scrollz

.include <bsd.port.mk>
