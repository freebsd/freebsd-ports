# Created by: Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
# $FreeBSD$

PORTNAME=	xmolwt
PORTVERSION=	0.7
PORTREVISION=	7
CATEGORIES=	biology
MASTER_SITES=	http://www.st.hirosaki-u.ac.jp/~rmiya/xmolwt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Calculate atom weight and percent of each element for a given formula

OPTIONS_DEFINE=	DOCS GTK2

USES=		gmake
MAKEFILE=	Makefile.gtk
ALL_TARGET=	gmolwt

PORTDOCS=	*
PLIST_FILES=	bin/gmolwt bin/molwt

GTK2_USES=		pkgconfig
GTK2_USE=	GNOME=gtk20
GTK2_MAKE_ENV=	GTKCONFIG="pkg-config gtk+-2.0"
GTK2_USE_OFF=	GNOME=gtk12
GTK2_MAKE_ENV_OFF=	GTKCONFIG="${GTK_CONFIG}"

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC/s| =| ?=| ; \
		/^CFLAGS/s| =| +=| ; \
		/^GTKCONFIG/s| =| ?=|' ${WRKSRC}/Makefile.gtk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmolwt ${STAGEDIR}${PREFIX}/bin
	${LN} -sf gmolwt ${STAGEDIR}${PREFIX}/bin/molwt
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} Howtouse.* Readme Xmolwt dot.gtkrc \
		*.html *.gif ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
