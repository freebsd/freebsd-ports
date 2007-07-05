# New ports collection makefile for:	xmms-iris
# Date created:				25 Apr 2002
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	iris
PORTVERSION=	0.12
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://cdelfosse.free.fr/xmms-iris/
PKGNAMEPREFIX=	xmms-

MAINTAINER=	dyeske@gmail.com
COMMENT=	An adaptation of the "OpenGL Spectrum Analyzer" from XMMS

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
PLIST_FILES=	lib/xmms/Visualization/libiris.so
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_GL=		yes
USE_X_PREFIX=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's|-lpthread|${PTHREAD_LIBS:S/"//g}|g' \
		-e '/objformat=/s|=.*|=elf|' \
			${WRKSRC}/configure

.include <bsd.port.mk>
