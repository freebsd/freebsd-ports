PORTNAME=	xdesktopwaves
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simulation of water waves on the desktop
WWW=		https://xdesktopwaves.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg
USE_XORG=	x11 xext

PLIST_FILES=	bin/xdesktopwaves \
		share/man/man1/xdesktopwaves.1.gz

.include <bsd.port.mk>
