# New ports collection makefile for:	xmms-faad
# Date created:			23 Feb, 2002
# Whom:				David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	faad2
PORTVERSION=	2.0
PORTREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	faac
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}-${PORTVERSION}-rc3

MAINTAINER=	dyeske@yahoo.com
COMMENT=	XMMS plugin for faad

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		xmms.4:${PORTSDIR}/multimedia/xmms \
		faad.0:${PORTSDIR}/audio/faad

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_AUTOMAKE_VER=	15
USE_AUTOHEADER=	yes
AUTOMAKE_ARGS=	--add-missing

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--program-transform-name='' --with-mp4v2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \

DESCR=		${PORTSDIR}/audio/faad/pkg-descr
MD5_FILE=	${PORTSDIR}/audio/faad/distinfo
PLIST_FILES=	lib/xmms/Input/libaac.so \
		lib/xmms/Input/libmp4.so

pre-patch: build-depends

post-patch:
# make sure everything is prepared prior to configure stage
# pre-configure will not work since *AUTO* tools happen in-between
	@cd ${WRKSRC}; ${ACLOCAL} -I ${ACLOCAL_DIR} -I .; \
		${SETENV} ${SCRIPTS_ENV} ${LIBTOOLIZE} --automake
# CFLAGS safeness
	@${FIND} ${WRKSRC} -type f -name Makefile.am | \
		${XARGS} -n 5 -x \
			${REINPLACE_CMD} -e \
				's|-O2|${CFLAGS}|'

post-configure:
# sync the multiple libtool copies
	@${CP} ${WRKSRC}/libtool ${WRKSRC}/common/mp4v2/
	@${CP} ${WRKSRC}/libtool ${WRKSRC}/plugins/xmms/
	@${CP} ${WRKSRC}/libtool ${WRKSRC}/plugins/xmmsmp4/

do-build:
	@cd ${WRKSRC}/plugins/xmms && ${MAKE}
	@cd ${WRKSRC}/plugins/xmmsmp4 && ${MAKE}

do-install:
	@cd ${WRKSRC}/plugins/xmms && ${MAKE} install
	@cd ${WRKSRC}/plugins/xmmsmp4 && ${MAKE} install

.include <bsd.port.mk>
