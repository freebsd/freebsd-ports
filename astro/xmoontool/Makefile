PORTNAME=	xmoontool
PORTVERSION=	3.0.3
PORTREVISION=	9
CATEGORIES=	astro
MASTER_SITES=	http://www.senax.net/xmoontool/

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	Version of John Walker's classical moontool for X11/Motif
WWW=		http://www.senax.net/xmoontool/xmoontool.html

USES=		motif xorg
USE_XORG=	x11 xt

PLIST_FILES=	bin/xmoontool share/man/man1/xmoontool.1.gz
PORTDOCS=	NOTES

OPTIONS_DEFINE=	DOCS LIBNOVA
OPTIONS_DEFAULT=	LIBNOVA

LIBNOVA_DESC=	High-accuracy astronomical model (libnova)
LIBNOVA_MAKE_ENV_OFF=	WITHOUT_LIBNOVA=yes
LIBNOVA_LIB_DEPENDS=	libnova.so:astro/libnova

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmoontool ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmoontool.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
