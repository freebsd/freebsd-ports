# New ports collection makefile for:	gnomevfs
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomevfs
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-vfs
DISTNAME=	gnome-vfs-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	msgfmt-new:${PORTSDIR}/devel/gettext-devel \
		${X11BASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc:${PORTSDIR}/misc/gnomemimedata
LIB_DEPENDS=	gconf-1.1:${PORTSDIR}/devel/gconf
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-mime-data-2.0.pc:${PORTSDIR}/misc/gnomemimedata

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOMELIBS=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		MSGFMT=${LOCALBASE}/bin/msgfmt-new \
		XGETTEXT=${LOCALBASE}/bin/xgettext-new \
		BSD_PTHREAD_LIBS=${PTHREAD_LIBS}

MAN5=		gnome-vfs-mime.5

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'
	@find ${WRKSRC} -name 'xml-i18n-*' | xargs ${PERL} -pi -e \
		's|/usr/local/bin/perl|${PERL}|g'

post-install:
	@if [ -L ${PREFIX}/include/libgnomevfs ]; then \
		${RM} -f ${PREFIX}/include/libgnomevfs; \
	fi
	${LN} -sf ${PREFIX}/include/gnome-vfs-1.0/libgnomevfs \
		${PREFIX}/include/libgnomevfs

.include <bsd.port.mk>
