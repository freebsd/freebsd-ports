PORTNAME=	xmulti
PORTVERSION=	2.00b4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.denpa.org/~go/xmulti/
DISTFILES=	xmul200b4.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 mascot based on gal-game "To Heart"

BROKEN_aarch64=	fails to build: fails to build: locale/mywchar.h:16:10: fatal error: 'machine/limits.h' file not found
BROKEN_riscv64=	fails to build: fails to build: locale/mywchar.h:16:10: fatal error: 'machine/limits.h' file not found

WRKSRC=		${WRKDIR}/xmulti200beta4

USES=		imake xorg
USE_XORG=	x11 xext xaw xmu xt xpm sm ice

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in MODULE.jp README.jp STYLESHEET.jp XMULTI.jp
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
