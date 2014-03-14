# Created by: Ryo MIYAMOTO <rmiya@cc.hirosaki-u.ac.jp>
# $FreeBSD$

PORTNAME=	xmolwt
PORTVERSION=	0.7
PORTREVISION=	5
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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USES+=		pkgconfig
USE_GNOME=	gtk20
MAKE_ENV+=	GTKCONFIG="pkg-config gtk+-2.0"
.else
USE_GNOME=	gtk12
MAKE_ENV+=	GTKCONFIG="${GTK_CONFIG}"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC/s| =| ?=| ; \
		/^CFLAGS/s| =| +=| ; \
		/^GTKCONFIG/s| =| ?=|' ${WRKSRC}/Makefile.gtk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmolwt ${PREFIX}/bin
	${LN} -sf gmolwt ${PREFIX}/bin/molwt
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/Howtouse.* ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/Readme ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/Xmolwt ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/dot.gtkrc ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/xmolwt
	${INSTALL_DATA} ${WRKSRC}/*.gif ${PREFIX}/share/doc/xmolwt
.endif

.include <bsd.port.mk>
