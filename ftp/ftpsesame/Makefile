# New ports collection makefile for:	ftpsesame
# Date created:				1 May 2006
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ftpsesame
PORTVERSION=	0.95
CATEGORIES=	ftp
MASTER_SITES=	http://www.sentia.org/downloads/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Helper for the FTP protocol get through your pf firewall

MAN8=		ftpsesame.8
PLIST_FILES=	bin/ftpsesame

MAKE_ARGS=	PREFIX=${PREFIX} MANPREFIX=${MANPREFIX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502106
IGNORE=		There is no pf(4) in the base system
.endif

.include <bsd.port.post.mk>
