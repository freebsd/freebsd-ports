# New ports collection makefile for:	xmms-faad
# Date created:			23 Feb, 2002
# Whom:				David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	faad2
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	faac
PKGNAMEPREFIX=	xmms-

MAINTAINER=	dyeske@yahoo.com
COMMENT=	XMMS plugin for faad

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		xmms.4:${PORTSDIR}/multimedia/xmms \
		faad.0:${PORTSDIR}/audio/faad \
		mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2
PATCH_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_AUTOTOOLS=	automake:15 autoheader:253 autoconf:253 libtool:15
AUTOMAKE_ARGS=		--add-missing
USE_X_PREFIX=		yes
USE_GNOME=		gtk12
USE_GMAKE=		yes

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-xmms --with-mp4v2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS} -DHAVE_GTK" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \

DESCR=		${PORTSDIR}/audio/faad/pkg-descr
MD5_FILE=	${PORTSDIR}/audio/faad/distinfo
PLIST_FILES=	lib/xmms/Input/libmp4.a \
		lib/xmms/Input/libmp4.la \
		lib/xmms/Input/libmp4.so

BUILD_WRKSRC=	${WRKSRC}/plugins/xmms/src
INSTALL_WRKSRC=	${WRKSRC}/plugins/xmms/src

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
		-e '/^_LT_AC_SHELL_INIT/d' ${WRKSRC}/aclocal.m4
# CFLAGS safeness
	@${FIND} ${WRKSRC} -type f -name Makefile.am | \
		${XARGS} -n 5 -x \
			${REINPLACE_CMD} -e \
				's|-O2|${CFLAGS}|'

.include <bsd.port.mk>
