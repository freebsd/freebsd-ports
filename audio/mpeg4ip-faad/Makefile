# New ports collection makefile for:	mpeg4ip-faad2
# Date created:			28 Sep 2004
# Whom:				Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	faad2
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	faac
PKGNAMEPREFIX=	mpeg4ip-

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	faad plugin for mpeg4ip

LIB_DEPENDS=	faad.0:${PORTSDIR}/audio/faad \
		mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2 \
		mp4.0:${PORTSDIR}/multimedia/mpeg4ip

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_AUTOMAKE_VER=	15
USE_AUTOHEADER_VER=	253
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
USE_REINPLACE=	yes
USE_SDL=	yes

CONFIGURE_ARGS=	--with-drm
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

INSTALLS_SHLIB=	yes

INSTALL_WRKSRC=	${WRKSRC}/plugins

PLIST_FILES=	lib/mp4player_plugin/faad2_plugin.a \
		lib/mp4player_plugin/faad2_plugin.so \
		lib/mp4player_plugin/faad2_plugin.so.0

.include <bsd.port.pre.mk>

pre-patch: build-depends

post-patch:
# make sure everything is prepared prior to configure stage
# pre-configure will not work since *AUTO* tools happen in-between
	@cd ${WRKSRC}; ${ACLOCAL} -I ${ACLOCAL_DIR} -I .; \
		${SETENV} ${SCRIPTS_ENV} ${LIBTOOLIZE} --automake
	@${REINPLACE_CMD} -e 's|$$lt_target|$$host|' \
		${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|<SDL/|<SDL11/|' \
		${WRKSRC}/plugins/mpeg4ip/faad2.cpp
	@${ECHO_CMD} "SUBDIRS = plugins" > \
		${WRKSRC}/Makefile.am
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|sys/inttypes.h|' \
		${WRKSRC}/common/mp4ff/mp4ff_int_types.h
.endif
# CFLAGS safeness
	@${FIND} ${WRKSRC} -type f -name Makefile.am | \
		${XARGS} -n 5 -x \
			${REINPLACE_CMD} -e \
				's|-O2|${CFLAGS}|'

.include <bsd.port.post.mk>
