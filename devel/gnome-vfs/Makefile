# New ports collection makefile for:	gnomevfs2
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomevfs2
PORTVERSION=	2.0.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	2.0.0/sources/gnome-vfs
DISTNAME=	gnome-vfs-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc:${PORTSDIR}/misc/gnomemimedata
LIB_DEPENDS=	gconf-2.5:${PORTSDIR}/devel/gconf2 \
		bonobo-2.0:${PORTSDIR}/devel/libbonobo
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc:${PORTSDIR}/misc/gnomemimedata

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--disable-gtk-doc \
		--with-gconf-source=xml::${PREFIX}/etc/gconf/gconf.xml.defaults
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		BSD_PTHREAD_LIBS=${PTHREAD_LIBS}
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
                 s|[(]libdir[)]/bonobo/servers|(prefix)/libdata/bonobo/servers|g'
	@find ${WRKSRC} -name "*info.in" | xargs ${REINPLACE_CMD} -e \
		's|\@datadir\@/gnome|\@datadir\@|g'

.include <bsd.port.mk>
