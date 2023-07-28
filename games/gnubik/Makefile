PORTNAME=	gnubik
PORTVERSION=	2.4.3
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	GNU

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D Rubik's cube game
WWW=		https://www.gnu.org/software/gnubik/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang gettext gl gmake gnome guile:2.2 \
		localbase pkgconfig
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
