# New ports collection makefile for:	xmps-win32-plugin
# Date created:		03 Feb 20001
# Whom:			Mario S F Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmps-win32-plugin
PORTVERSION=	0.0.4
CATEGORIES=	graphics
MASTER_SITES=	http://xmps.sourceforge.net/sources/

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	xmps.0:${PORTSDIR}/graphics/xmps \
		intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_GTK=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB=	LIB_VERSION="${LIB_VERSION}"

#CODEC_PORT=	${PORTSDIR}/graphics/win32-codecs
CODEC_PORT=	${.CURDIR}/../win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE
LIB_VERSION=	0

post-patch:
	${PERL} -pi -ne "s|/usr/lib/win32|${LOCALBASE}/lib/win32|" ${WRKSRC}/src/win32_codec.c

post-install:
	@${LN} -sf libwin32.so ${PREFIX}/lib/xmps/codecs/video/libwin32.so.${LIB_VERSION}

.include <bsd.port.mk>
