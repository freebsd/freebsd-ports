PORTNAME=	wmpuzzle
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://people.debian.org/~godisch/wmpuzzle/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockable puzzle game for WindowMaker and AfterStep
WWW=		https://people.debian.org/~godisch/wmpuzzle/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		gmake localbase:ldflags xorg
USE_XORG=	x11 xext xpm
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	bin/wmpuzzle share/man/man6/wmpuzzle.6.gz

CPPFLAGS+=	-DBSD
# Fix build with clang 11
CFLAGS+=	-fcommon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpuzzle ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmpuzzle.6 ${STAGEDIR}${PREFIX}/share/man/man6

.include <bsd.port.mk>
