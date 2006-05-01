# New ports collection makefile for:	ftpsesame
# Date created:				1 May 2006
# Whom:					Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ftpsesame
PORTVERSION=	0.95
CATEGORIES=	ftp
MASTER_SITES=	http://www.sentia.org/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sem

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Helper for pf firewall to pass FTP protocol

MAN8=		ftpsesame.8
PLIST_FILES=	bin/ftpsesame
USE_RC_SUBR=	ftpsesame.sh

MAKE_ARGS=	PREFIX=${PREFIX} MANPREFIX=${MANPREFIX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502106
IGNORE=		there is no pf(4) in the base system
.endif

.include <bsd.port.post.mk>
