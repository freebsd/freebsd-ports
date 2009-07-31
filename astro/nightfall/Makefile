# New ports collection makefile for:      nightfall
# Date created:         21 February 2002
# Whom:                 Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	nightfall
PORTVERSION=	1.70
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://www.la-samhna.de/nightfall/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive binary star application

OPTIONS=	GNOMEUI "Enable LibGnomeUI support" off \
		PGPLOT "Enable PGPLOT support" on \
		OPENGL "Enable OpenGL support" on

USE_GNOME=	gnomehack gnomehier gnometarget gtk20
USE_PERL5=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-locale-prefix=${PREFIX}/share/locale

MAN1=		nightfall.1

.include <bsd.port.pre.mk>

.if defined(WITH_GNOMEUI)
USE_GNOME+=	gnomeprefix libgnomeui
CONFIGURE_ARGS+=	--with-gnomedoc-prefix=${PREFIX}/share
INSTALLS_OMF=	yes
PLIST_SUB+=	GNOMEUI=""
.else
CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUB+=	GNOMEUI="@comment "
.endif

.if defined(WITHOUT_PGPLOT)
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
CONFIGURE_ARGS+=	--with-gnuplot
.else
LIB_DEPENDS+=	pgplot.5:${PORTSDIR}/graphics/pgplot
USE_FORTRAN=	yes
CONFIGURE_ARGS+=	--with-pgplot-include=${LOCALBASE}/include \
			--with-pgplot-lib=${LOCALBASE}/lib
.endif

.if defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=	--disable-opengl
.else
LIB_DEPENDS+=	gtkgl-2.0.1:${PORTSDIR}/x11-toolkits/gtkglarea2
USE_GL=		glut
CONFIGURE_ARGS+=	--with-lib-GL
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS -O3|CFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^Icon=gnome|Icon=${DATADIR}/pixmaps|g' \
		${WRKSRC}/nightfall.desktop

post-install:
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/nightfall.desktop \
		${PREFIX}/share/applications

.include <bsd.port.post.mk>
