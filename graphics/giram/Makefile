# New ports collection makefile for:	giram
# Date created:        17 June 1999
# Whom:                Brandon Fosdick <bfoz@glue.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	giram
PORTVERSION=	0.3.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.giram.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Giram is Really A Modeller

RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray31

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_MESA=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gl=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibcapplet}!=""
USE_GNOME+=	libcapplet
PKGNAMESUFFIX=	-gnome
.else
CONFIGURE_ARGS+=--disable-gnome
.endif

pre-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS:S/"//g}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$(top_builddir)/intl/libintl.a|-lintl|g' \
		 ${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/share/doc/giram/SampleScenes
	#${INSTALL_DATA} ${WRKSRC}/SampleScenes/* ${PREFIX}/share/doc/giram/SampleScenes/

.include <bsd.port.post.mk>
