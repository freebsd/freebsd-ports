# New ports collection makefile for:    The GIMP
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gimp
PORTVERSION=	1.3.11
PORTEPOCH=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		ftp://ftp.ameth.org/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,} \
		ftp://ftp.bic.mni.mcgill.ca/pub/mpeg/:mpeg \
		http://starship.python.net/~gward/mpeglib/:mpeg
MASTER_SITE_SUBDIR=	gimp/v${PORTVERSION:R}/v${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		mpeg_lib-1.3.1.tar.gz:mpeg

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20 \
		gimpprint.1:${PORTSDIR}/print/gimp-print \
		art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2 \
		aa.1:${PORTSDIR}/graphics/aalib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

SHLIBVER?=	2

NO_LATEST_LINK=	yes

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
PLIST_SUB=	SHLIBVER="${SHLIBVER}"
CONFIGURE_ARGS=	--disable-perl \
		--with-html-dir=${PREFIX}/share/doc/gimp \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include -I${MPEG_WRKSRC}" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

GIMP_DISTFILE=	${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
MPEG_DISTFILE=	${DISTDIR}/mpeg_lib-1.3.1.tar.gz
MPEG_WRKSRC=	${WRKDIR}/mpeg_lib-1.3.1
MPEG_CONFIGURE_ENV=	OPTIMIZE="${CFLAGS}"
MPEG_CONFIGURE_ARGS=	--prefix=${PREFIX} \
			--target=${ARCH}-unknown-freebsd${OSREL}

MAN1=		gimp-1.3.1 gimptool-1.3.1 gimp-remote-1.3.1
MAN5=		gimprc-1.3.5

.if exists(${X11BASE}/libdata/pkgconfig/libpanelapplet-2.0.pc)
RUN_DEPENDS+=	gnome-panel:${PORTSDIR}/x11/gnomepanel
CONFIGURE_ARGS+=	--with-gnome-desktop=${X11BASE}/share/gnome/applications
PLIST_SUB+=	GNOME:=""
.else
PLIST_SUB+=	GNOME:="@comment "
.endif

#.if exists(${X11BASE}/libdata/pkgconfig/libgtkhtml-2.0.pc) || defined(WITH_HTML_HELP_BROWSER)
#LIB_DEPENDS+=	gtkhtml-2.0:${PORTSDIR}/www/libgtkhtml
#.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@(cd ${WRKDIR} && ${BZIP2_CMD} -dc ${GIMP_DISTFILE} | ${TAR} -xf -)
	@(cd ${WRKDIR} && ${GZIP_CMD} -dc ${MPEG_DISTFILE} | ${TAR} -xf -)
	@(${FIND} ${MPEG_WRKSRC} -type f | ${XARGS} ${CHMOD} u+w)

pre-configure:
	@(cd ${MPEG_WRKSRC} && \
		${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		${MPEG_CONFIGURE_ENV} ./configure ${MPEG_CONFIGURE_ARGS})
	@(cd ${MPEG_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-patch:
	@${REINPLACE_CMD} -e 's|-lmpeg|${MPEG_WRKSRC}/libmpeg.a|g' \
		${WRKSRC}/configure
	@(cd ${MPEG_WRKSRC} ; \
		${GREP} -r -l "<malloc.h>" * | \
		${XARGS} ${REINPLACE_CMD} -e "s/<malloc.h>/<stdlib.h>/")

.include <bsd.port.mk>
