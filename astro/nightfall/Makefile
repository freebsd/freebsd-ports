# Created by: Christian Brueffer <chris@unixpages.org>
# $FreeBSD$

PORTNAME=	nightfall
PORTVERSION=	1.86
PORTREVISION=	4
CATEGORIES=	astro
MASTER_SITES=	http://www.la-samhna.de/nightfall/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive binary star application

USES=		compiler gettext gmake pathfix perl5 pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-locale-prefix=${PREFIX}/share/locale

OPTIONS_DEFINE=		GNOME PGPLOT OPENGL
OPTIONS_DEFAULT=	PGPLOT OPENGL
OPTIONS_SUB=		yes

GNOME_CONFIGURE_ON=	--with-gnomedoc-prefix=${PREFIX}/share
GNOME_CONFIGURE_OFF=	--disable-gnome
GNOME_USE=		GNOME=gnomeprefix,libgnomeui
GNOME_VARS=		INSTALLS_OMF=yes

OPENGL_CONFIGURE_ON=	--with-lib-GL
OPENGL_CONFIGURE_OFF=	--disable-opengl
OPENGL_LIB_DEPENDS=	libgtkgl-2.0.so:x11-toolkits/gtkglarea2
OPENGL_USE=		GL=glut

PGPLOT_DESC=		PGPLOT support
PGPLOT_CONFIGURE_ON=	--with-pgplot-include=${LOCALBASE}/include \
			--with-pgplot-lib=${LOCALBASE}/lib
PGPLOT_CONFIGURE_OFF=	--with-gnuplot
PGPLOT_LIB_DEPENDS=	libpgplot.so:graphics/pgplot
PGPLOT_RUN_DEPENDS_OFF=	gnuplot:math/gnuplot
PGPLOT_USES=		fortran

.include <bsd.port.pre.mk>

post-patch:
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e 's|-fforce-addr||' ${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|CFLAGS -O3|CFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^Icon=gnome|Icon=${DATADIR}/pixmaps|g' \
		${WRKSRC}/nightfall.desktop

post-install:
	${INSTALL_DATA} ${WRKSRC}/nightfall.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.post.mk>
