# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

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
USE_RC_SUBR=	ftpsesame

MAKE_ARGS=	PREFIX=${PREFIX} MANPREFIX=${MANPREFIX}

NO_STAGE=	yes
.include <bsd.port.mk>
