# New ports collection makefile for:	faad
# Date created:			8 January 2003
# Whom:				Sean McGovern <sean@sfarc.net>
#
# $FreeBSD$
#

PORTNAME=	faad2
PORTVERSION=	2.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	faac

MAINTAINER=	ahze@ahze.net
COMMENT=	A LC, MAIN and LTP profile, MPEG2 and MPEG-4 AAC decoder

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile

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
WANT_SDL=	yes

CONFIGURE_ARGS=	--with-mp4v2 --with-drm
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \

INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MPEG4IP)
PLIST_SUB+=	WITHOUT_MPEG4IP="" PLUGIN="@comment "
.else
LIB_DEPENDS+=	mp4.0:${PORTSDIR}/multimedia/mpeg4ip
USE_SDL=	sdl
PLIST_SUB+=	WITHOUT_MPEG4IP="@comment " PLUGIN=""
.endif

pre-everything::
	@${ECHO_MSG} "===>"
.if !defined(WITHOUT_MPEG4IP)
	@${ECHO_MSG} "===> you can disable mpeg4ip support by"
	@${ECHO_MSG} "===> defining WITHOUT_MPEG4IP"
.else
	@${ECHO_MSG} "===> WARNING: WITHOUT_MPEG4IP is defined"
	@${ECHO_MSG} "===> Having WITHOUT_MPEG4IP defined conflicts"
	@${ECHO_MSG} "===> with multimedia/mpeg4ip and you will not"
	@${ECHO_MSG} "===> be able to install mpeg4ip after you install faad2"
.endif
	@${ECHO_MSG} "===>"

pre-patch: build-depends

post-patch:
# make sure everything is prepared prior to configure stage
# pre-configure will not work since *AUTO* tools happen in-between
	@cd ${WRKSRC}; ${ACLOCAL} -I ${ACLOCAL_DIR} -I .; \
		${SETENV} ${SCRIPTS_ENV} ${LIBTOOLIZE} --automake
	@${REINPLACE_CMD} -e 's|$$lt_target|$$host|' \
		${WRKSRC}/aclocal.m4
.if !defined(WITHOUT_MPEG4IP)
	@${REINPLACE_CMD} -e 's|<SDL|<SDL11|' \
		${WRKSRC}/plugins/mpeg4ip/faad2.cpp
.endif
	@${ECHO_CMD} "SUBDIRS = libfaad common frontend plugins" > \
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
post-install:
.if defined(WITHOUT_MPEG4IP)
	@${INSTALL_DATA} ${WRKSRC}/common/mp4v2/systems.h ${PREFIX}/include
.endif

.include <bsd.port.post.mk>
