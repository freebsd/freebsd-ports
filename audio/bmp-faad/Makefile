# New ports collection makefile for:	bmp-faad
# Date created:			2 Sep, 2004
# Whom:				Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	faad2
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	faac
PKGNAMEPREFIX=	bmp-

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Beep Media Player (BMP) plugin for faad

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		faad.0:${PORTSDIR}/audio/faad \
		beep.2:${PORTSDIR}/multimedia/beep-media-player

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_AUTOMAKE_VER=	15
USE_AUTOCONF_VER=	253
USE_AUTOHEADER_VER=	253
USE_INC_LIBTOOL_VER=	13
AUTOMAKE_ARGS=		--add-missing
USE_X_PREFIX=		yes
USE_GMAKE=		yes
USE_GNOME=		gtk20
USE_REINPLACE=		yes

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-xmms --with-mp4v2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS} -DHAVE_GTK" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \

DESCR=		${PORTSDIR}/audio/faad/pkg-descr
MD5_FILE=	${PORTSDIR}/audio/faad/distinfo
PLIST_FILES=	lib/bmp/Input/libmp4.so

BUILD_WRKSRC=	${WRKSRC}/plugins/xmms/src
INSTALL_WRKSRC=	${WRKSRC}/plugins/xmms/src

.include <bsd.port.pre.mk>

pre-patch: build-depends

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/plugins/xmms/src/Makefile.am
	@${REINPLACE_CMD} -e 's|"faad.h"|<faad.h>|; s|"mp4.h"|<mp4.h>|' \
		${WRKSRC}/plugins/xmms/src/libmp4.c
# make sure everything is prepared prior to configure stage
# pre-configure will not work since *AUTO* tools happen in-between
	@cd ${WRKSRC}; ${ACLOCAL} -I ${ACLOCAL_DIR} -I .; \
		${SETENV} ${SCRIPTS_ENV} ${LIBTOOLIZE} --automake
	@${REINPLACE_CMD} -e 's|$$lt_target|$$host|' \
		${WRKSRC}/aclocal.m4
# CFLAGS safeness
	@${FIND} ${WRKSRC} -type f -name Makefile.am | \
		${XARGS} -n 5 -x \
			${REINPLACE_CMD} -e \
				's|-O2|${CFLAGS}|'
	@${REINPLACE_CMD} -e 's|<xmms|<bmp|' ${WRKSRC}/plugins/xmms/src/libmp4.c

.include <bsd.port.post.mk>
