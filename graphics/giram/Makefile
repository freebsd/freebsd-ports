# New ports collection makefile for:	giram
# Date created:        17 June 1999
# Whom:                Brandon Fosdick <bfoz@glue.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	giram
PORTVERSION=	0.1.7
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.giram.org/pub/
DISTNAME=	Giram-${PORTVERSION}

MAINTAINER=	bfoz@glue.umd.edu

RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray31

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GMAKE=	yes
USE_GTK=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gl=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
.else
CONFIGURE_ARGS+=--disable-gnome
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS:S/"//g}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/share/doc/giram/SampleScenes
	${INSTALL_DATA} ${WRKSRC}/SampleScenes/* ${PREFIX}/share/doc/giram/SampleScenes/

.include <bsd.port.post.mk>
