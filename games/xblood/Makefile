PORTNAME=	xblood
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://kozos.jp/myfreesoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makes the root window bloody
WWW=		https://kozos.jp/myfreesoft/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" X11BASE="${LOCALBASE}"
USES=		xorg
USE_XORG=	x11
PLIST_FILES=	bin/xblood share/man/man1/xblood.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xblood ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xblood.1.gz ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
