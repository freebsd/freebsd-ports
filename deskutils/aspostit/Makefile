# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aspostit
PORTVERSION=	1.3
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	AFTERSTEP/apps/aspostit

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AfterStep dockable version of XPostIt

LICENSE=	GPLv2+

USE_XORG=	xpm xaw xext x11
USES=		gmake jpeg
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/aspostit man/man1/aspostit.1.gz

post-extract:
	@${LN} -sf aspostit.man ${WRKSRC}/aspostit.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aspostit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aspostit.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
