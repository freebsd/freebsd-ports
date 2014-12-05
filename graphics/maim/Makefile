# $FreeBSD$

PORTNAME=	maim
PORTVERSION=	3.3.41
CATEGORIES=	graphics

MAINTAINER=	neel@neelc.org
COMMENT=	Screenshot utility with performance improvements over scrot

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	naelstrof
GH_PROJECT=	maim
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	178b253

USES=		cmake
USE_EFL=	imlib2
USE_XORG=	x11 xrandr xfixes
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man-src/${PORTNAME}.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
