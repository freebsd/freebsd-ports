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

PLIST_FILES=	bin/ftpsesame man/man8/ftpsesame.8.gz
USE_RC_SUBR=	ftpsesame

MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX} MANPREFIX=${STAGEDIR}${MANPREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ftpsesame ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ftpsesame.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
