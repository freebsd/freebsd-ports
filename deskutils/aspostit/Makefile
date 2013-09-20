# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aspostit
PORTVERSION=	1.3
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	AFTERSTEP/apps/aspostit

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AfterStep dockable version of XPostIt

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

USE_XORG=	xpm xaw xext x11
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		aspostit.1
PLIST_FILES=	bin/aspostit

NO_STAGE=	yes
post-extract:
	@${LN} -sf aspostit.man ${WRKSRC}/aspostit.1

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} aspostit ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} aspostit.1 ${MANPREFIX}/man/man1)

.include <bsd.port.mk>
