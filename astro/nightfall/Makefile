# New ports collection makefile for:      nightfall
# Date created:         21 February 2002
# Whom:                 Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	nightfall
PORTVERSION=	1.70
PORTREVISION=	7
CATEGORIES=	astro
MASTER_SITES=	http://www.la-samhna.de/nightfall/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive binary star application

OPTIONS_DEFINE=	GNOME PGPLOT OPENGL
OPTIONS_DEFAULT=	PGPLOT OPENGL
PGPLOT_DESC=	Enable PGPLOT support

USE_GNOME=	gnomehack gnomehier gtk20
USE_PERL5=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-locale-prefix=${PREFIX}/share/locale

MAN1=		nightfall.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOMEUI}
USE_GNOME+=	gnomeprefix libgnomeui
CONFIGURE_ARGS+=	--with-gnomedoc-prefix=${PREFIX}/share
INSTALLS_OMF=	yes
PLIST_SUB+=	GNOMEUI=""
.else
CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUB+=	GNOMEUI="@comment "
.endif

.if ${PORT_OPTIONS:MPGPLOT}
LIB_DEPENDS+=	pgplot.5:${PORTSDIR}/graphics/pgplot
USE_FORTRAN=	yes
CONFIGURE_ARGS+=	--with-pgplot-include=${LOCALBASE}/include \
			--with-pgplot-lib=${LOCALBASE}/lib
.else
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
CONFIGURE_ARGS+=	--with-gnuplot
.endif

.if ${PORT_OPTIONS:MOPENGL}
LIB_DEPENDS+=	gtkgl-2.0.1:${PORTSDIR}/x11-toolkits/gtkglarea2
USE_GL=		glut
CONFIGURE_ARGS+=	--with-lib-GL
.else
CONFIGURE_ARGS+=	--disable-opengl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS -O3|CFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^Icon=gnome|Icon=${DATADIR}/pixmaps|g' \
		${WRKSRC}/nightfall.desktop

post-install:
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/nightfall.desktop \
		${PREFIX}/share/applications

.include <bsd.port.mk>
