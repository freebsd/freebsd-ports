# New ports collection makefile for:      nightfall
# Date created:         21 February 2002
# Whom:                 Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	nightfall
PORTVERSION=	1.37
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://www.lsw.uni-heidelberg.de/users/rwichman/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive binary star application

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_PERL5=	yes
USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_GNOME=	gtk12 gnometarget
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-locale-prefix=${PREFIX}/share/locale

MAN1=		nightfall.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
PKGNAMESUFFIX=	-gnome
USE_GNOME+=	gnomelibs gnomeprefix
DATADIR=	${PREFIX}/share/gnome/${PORTNAME}
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.if defined(WITHOUT_PGPLOT)
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
CONFIGURE_ARGS+=	--with-gnuplot
.else
LIB_DEPENDS+=	pgplot.5:${PORTSDIR}/graphics/pgplot
CONFIGURE_ARGS+=	--with-pgplot-include=${LOCALBASE}/include \
			--with-pgplot-lib=${LOCALBASE}/lib
.endif

.if defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=	--disable-opengl
.else
LIB_DEPENDS+=	glut.3:${PORTSDIR}/graphics/libglut \
		gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
CONFIGURE_ARGS+=	--with-lib-GL
.endif

pre-everything::
	@${ECHO_MSG} "Nightfall has the following tunable option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITHOUT_GNOME=gnomelibs		Turns off Gnome support"
	@${ECHO_MSG} "	WITHOUT_PGPLOT=yes		Turns off PGPLOT support"
	@${ECHO_MSG} "	WITHOUT_OPENGL=yes		Turns off OpenGL support"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS -O3|CFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(GNOME_DATADIR)/gnome/|(GNOME_DATADIR)/|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
