# New ports collection makefile for:      nightfall
# Date created:         21 February 2002
# Whom:                 Christian Brueffer <chris@unixpages.org>
#
# $FreeBSD$
#

PORTNAME=	nightfall
PORTVERSION=	1.32
CATEGORIES=	astro
MASTER_SITES=	http://www.lsw.uni-heidelberg.de/~rwichman/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive binary star application

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

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
PLIST_SUB+=	NFDATADIR="share/gnome"
.else
CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUB+=	NFDATADIR="share"
.endif

.if defined(WITHOUT_PGPLOT)
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
CONFIGURE_ARGS+=	--with-gnuplot
.else
LIB_DEPENDS+=	pgplot.5:${PORTSDIR}/graphics/pgplot
CONFIGURE_ARGS+=	--with-pgplot-include=${LOCALBASE}/include \
			--with-pgplot-lib=${LOCALBASE}/lib
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS -O3|CFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(GNOME_DATADIR)/gnome/|(GNOME_DATADIR)/|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
