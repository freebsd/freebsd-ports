# New ports collection makefile for:	gnomevfs
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomevfs
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-vfs
DISTNAME=	gnome-vfs-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc:${PORTSDIR}/misc/gnomemimedata
LIB_DEPENDS=	gconf-1.1:${PORTSDIR}/devel/gconf \
		iconv.3:${PORTSDIR}/converters/libiconv
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc:${PORTSDIR}/misc/gnomemimedata

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOMELIBS=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		BSD_PTHREAD_LIBS=${PTHREAD_LIBS}

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'
	@find ${WRKSRC} -name 'xml-i18n-*' | xargs ${PERL} -pi -e \
		's|/usr/local/bin/perl|${PERL}|g'

.include <bsd.port.mk>
