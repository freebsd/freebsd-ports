# Created by: asami
# $FreeBSD$

PORTNAME=	xgrasp
PORTVERSION=	1.7d
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	XCONTRIB/../R5contrib
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display GL animations on X screen

NO_WRKSUBDIR=	yes

USES=		imake tar:Z xorg
USE_XORG=	x11 xext

PLIST_FILES=	bin/glib bin/xgrasp \
		man/man1/glib.1.gz man/man1/xgrasp.1.gz

.include <bsd.port.mk>
