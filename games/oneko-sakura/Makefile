PORTNAME=	oneko
DISTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.daidouji.com/oneko/distfiles/
PKGNAMESUFFIX=	-sakura
DISTNAME=	${PORTNAME}-${DISTVERSION}.sakura.5

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Cat, Sakura or Tomoyo chasing a mouse all over the screen
WWW=		http://www.daidouji.com/oneko/

# Converted from NO_CDROM
LICENSE=	oneko
LICENSE_NAME=	oneko
LICENSE_TEXT=	Including derivatives from CARDCAPTOR SAKURA. See http://www.clamp-net.com/ -> INFORMATION
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		imake xorg
USE_XORG=	x11 xext
PLIST_FILES=	bin/oneko \
		share/man/man6/oneko.6.gz

.include <bsd.port.mk>
