# New ports collection makefile for:    The GIMP
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gimp
PORTVERSION=	1.2.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/gimp/%SUBDIR%,} \
		ftp://ftp.bic.mni.mcgill.ca/pub/mpeg/:mpeg \
		http://starship.python.net/~gward/mpeglib/:mpeg
MASTER_SITE_SUBDIR=	gimp/v${PORTVERSION:R}/v${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		mpeg_lib-1.3.1.tar.gz:mpeg

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The GNU Image Manipulation Program

LIB_DEPENDS=	aa.1:${PORTSDIR}/graphics/aalib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

DEPRECATED=	New stable release 2.0 can be installed via graphics/gimp port

NO_LATEST_LINK=	yes

CONFLICTS=	gimp-2.* gimp-gnome-2.*

#SHLIBVER?=	${PORTVERSION:S/1.2.//g}
SHLIBVER?=	2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_INC_LIBTOOL_VER=13
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
PLIST_SUB=	SHLIBVER="${SHLIBVER}"
CONFIGURE_ARGS=	--disable-perl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${MPEG_WRKSRC}" \
		LDFLAGS="-L${LOCALBASE}/lib"

GIMP_DISTFILE=	${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
MPEG_DISTFILE=	${DISTDIR}/mpeg_lib-1.3.1.tar.gz
MPEG_WRKSRC=	${WRKDIR}/mpeg_lib-1.3.1
MPEG_CONFIGURE_ENV=	OPTIMIZE="${CFLAGS}"
MPEG_CONFIGURE_ARGS=	--prefix=${PREFIX} \
			--target=${ARCH}-unknown-freebsd${OSREL}

MAN1=		gimp.1 gimptool.1 gimp-remote.1 \
		gimp-1.2.1 gimp-remote-1.2.1 gimptool-1.2.1
MAN5=		gimprc.5 gimprc-1.2.5

.if defined(WITHOUT_PRINT)
CONFIGURE_ARGS+=	--disable-print
PLIST_SUB+=		PRINT="@comment "
.else
LIB_DEPENDS+=		gimpprint.2:${PORTSDIR}/print/gimp-print
PLIST_SUB+=		PRINT=""
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The Gimp has the following tunable option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITHOUT_PRINT=yes	Turns off GIMP printing"
	@${ECHO_MSG} ""

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

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/gimp.setfont ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
