# Created by: HOTARU-YA <hotaru@tail.net>

PORTNAME=	oneko
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.daidouji.com/oneko/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}.sakura.5
PKGNAMESUFFIX=	-sakura

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cat, Sakura or Tomoyo chasing a mouse all over the screen

# Converted from NO_CDROM
LICENSE=	oneko
LICENSE_NAME=	oneko
LICENSE_TEXT=	Including derivatives from CARDCAPTOR SAKURA. See http://www.clamp-net.com/ -> INFORMATION
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

CONFLICTS=	oneko-2.*

USES=		imake xorg
USE_XORG=	x11 xext
PLIST_FILES=	bin/oneko \
		man/man6/oneko.6.gz

pre-configure:
	@${REINPLACE_CMD} -e 's,/\*\*/# Cannot compile in using Gcc,/* Cannot compile using Gcc */,' \
		${WRKSRC}/Imakefile
	@${ECHO_CMD} "MANSUFFIX=6" >>${WRKSRC}/Imakefile

post-configure:
	@${REINPLACE_CMD} -e 's,^all:: oneko\..*\.html$$,,' \
			  -e 's,^install.man:: oneko\..*\.html$$,do-nada:,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
