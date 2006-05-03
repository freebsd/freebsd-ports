# New ports collection makefile for:	bmp-faad
# Date created:			2 Sep, 2004
# Whom:				Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	faad2
PORTVERSION=	2.0
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	faac
PKGNAMEPREFIX=	bmp-

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Beep Media Player (BMP) plugin for faad

PATCH_DEPENDS=	${AUTOMAKE_DEPENDS} ${AUTOCONF_DEPENDS} ${LIBTOOL_DEPENDS}
LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		faad.0:${PORTSDIR}/audio/faad \
		mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2 \
		beep.2:${PORTSDIR}/multimedia/beep-media-player

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_AUTOTOOLS=	automake:15 autoheader:253 autoconf:253 libtool:15
AUTOMAKE_ARGS=		--add-missing
USE_X_PREFIX=		yes
USE_GMAKE=		yes
USE_GNOME=		gtk20

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-xmms --with-mp4v2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS} -DHAVE_GTK" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \

DESCR=		${PORTSDIR}/audio/faad/pkg-descr
MD5_FILE=	${PORTSDIR}/audio/faad/distinfo
PLIST_FILES=	lib/bmp/Input/libmp4.a \
		lib/bmp/Input/libmp4.la \
		lib/bmp/Input/libmp4.so

BUILD_WRKSRC=	${WRKSRC}/plugins/xmms/src
INSTALL_WRKSRC=	${WRKSRC}/plugins/xmms/src

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/plugins/xmms/src/Makefile.am
	@${REINPLACE_CMD} -e 's|"faad.h"|<faad.h>|; s|"mp4.h"|<mp4.h>|' \
		${WRKSRC}/plugins/xmms/src/libmp4.c
# make sure everything is prepared prior to configure stage
# pre-configure will not work since *AUTO* tools happen in-between
	@cd ${WRKSRC}; ${ACLOCAL} -I ${ACLOCAL_DIR} -I .; \
		${SETENV} ${SCRIPTS_ENV} ${LIBTOOLIZE} --automake
	@${REINPLACE_CMD} -e 's|$$lt_target|$$host|' \
		-e '/^_LT_AC_SHELL_INIT/d' ${WRKSRC}/aclocal.m4
# CFLAGS safeness
	@${FIND} ${WRKSRC} -type f -name Makefile.am | \
		${XARGS} -n 5 -x \
			${REINPLACE_CMD} -e \
				's|-O2|${CFLAGS}|'
	@${REINPLACE_CMD} -e 's|<xmms|<bmp|' ${WRKSRC}/plugins/xmms/src/libmp4.c

.include <bsd.port.post.mk>
