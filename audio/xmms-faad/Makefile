# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	faad2
PORTVERSION=	2.7
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/faac/${PORTNAME}-src/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	xmms-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS plugin for MP4/M4A/AAC files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../../../COPYING

LIB_DEPENDS=	libxmms.so:multimedia/xmms \
		libfaad.so:audio/faad

WRKSRC_SUBDIR=	plugins/xmms/src

USE_GNOME=	gtk12
USES=		pkgconfig tar:bzip2
WANT_GNOME=	yes
EXTRA_CFLAGS=	`xmms-config --cflags`
EXTRA_LDFLAGS=	`xmms-config --libs`

PLUGINS_DIR=	${PREFIX}/lib/xmms/Input
PLIST_FILES=	${PLUGINS_DIR:S,^${PREFIX}/,,}/libmp4.so

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -fPIC -shared \
		-I${LOCALBASE}/include -DHAVE_STDINT_H \
		${EXTRA_CFLAGS} *.c -o libmp4.so \
		-L${LOCALBASE}/lib -lfaad -lmp4ff \
		${EXTRA_LDFLAGS}

do-install:
	@${MKDIR} ${STAGEDIR}${PLUGINS_DIR}
	${INSTALL_LIB} ${WRKSRC}/libmp4.so ${STAGEDIR}${PLUGINS_DIR}

.include <bsd.port.mk>
