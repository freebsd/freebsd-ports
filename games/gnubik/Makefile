PORTNAME=	gnubik
PORTVERSION=	2.4.3
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D Rubik's cube game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libguile-2.2.so:lang/guile2 \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang gettext gl gmake gnome localbase pkgconfig
USE_GNOME=	gtk20
USE_GL=		gl glu

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

INFO=		gnubik

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,guile-2\.0,guile-2.2,' \
		${WRKSRC}/configure

post-install:
	${LN} -s ../icons/hicolor/32x32/apps/gnubik.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
