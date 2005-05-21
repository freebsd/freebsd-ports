# New ports collection makefile for:	bmp-flac
# Date created:				2005-05-22
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	flac
PORTVERSION=	20040316
CATEGORIES=	audio
MASTER_SITES=	http://ccm.sherry.jp/tmp/
PKGNAMEPREFIX=	bmp-
DISTNAME=	${PORTNAME}-CVS-${PORTVERSION}-with-bmp-plugin

MAINTAINER=	nork@FreeBSD.org
COMMENT=	FLAC input plugin for beep-media-player

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player \
		FLAC.7:${PORTSDIR}/audio/flac

PLIST_FILES=	lib/bmp/Input/libbmp-flac.so

USE_BZIP2=	yes
USE_X_PREFIX=	yes
##GNU_CONFIGURE=	yes
USE_INC_LIBTOOL_VER=15
CONFIGURE_ARGS=	--with-libiconv-prefix="${LOCALBASE}" \
		--with-ogg="${LOCALBASE}" \
		--with-xmms-prefix="${X11BASE}"

MAKEFILE=	${FILESDIR}/Makefile

# "obj" is magic to our make(1)
post-configure:
	@${RM} -rf ${WRKSRC}/obj

# This is to avoid libtool running ldconfig -m ${X11BASE}/lib/bmp/Input
do-install:
	${INSTALL_DATA} ${WRKSRC}/src/plugin_bmp/.libs/libbmp-flac.so ${PREFIX}/lib/bmp/Input

.include <bsd.port.mk>
