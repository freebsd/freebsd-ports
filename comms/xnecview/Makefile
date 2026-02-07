PORTNAME=	xnecview
DISTVERSION=	1.37
CATEGORIES=	comms hamradio
MASTER_SITES=	https://wwwhome.cs.utwente.nl/%7Eptdeboer/ham/xnecview/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	X11 viewer of NEC2 input and output data
WWW=		https://wwwhome.cs.utwente.nl/%7Eptdeboer/ham/xnecview/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake gnome pkgconfig tar:tgz
USE_GNOME=	gtk20

PLIST_FILES=	bin/xnecview share/man/man1/xnecview.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xnecview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xnecview.man \
		${STAGEDIR}${PREFIX}/share/man/man1/xnecview.1

.include <bsd.port.mk>
