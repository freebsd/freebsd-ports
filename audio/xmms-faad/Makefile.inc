# $FreeBSD$

PORTNAME=	faad2
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SFE/faac

BUILD_DEPENDS=	faad2>=2.7:${PORTSDIR}/audio/faad
RUN_DEPENDS=	faad2>=2.7:${PORTSDIR}/audio/faad

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/plugins/xmms/src

USE_BZIP2=	yes
WANT_GNOME=	yes

DESCR=		${PORTSDIR}/audio/faad/pkg-descr
PLIST_FILES=	${PLUGINS_DIR:S,^${PREFIX}/,,}/libmp4.so

.include <bsd.port.pre.mk>

.if ${PKGNAMEPREFIX} == "bmp-"
LIB_DEPENDS+=	beep.2:${PORTSDIR}/multimedia/beep-media-player
USE_GNOME+=	gtk20
PLUGINS_DIR=	${PREFIX}/lib/bmp/Input
EXTRA_CFLAGS=	`pkg-config --cflags bmp` -DHAVE_BMP
EXTRA_LDFLAGS=	`pkg-config --libs bmp`
.endif

.if ${PKGNAMEPREFIX} == "xmms-"
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
USE_GNOME+=	gtk12
PLUGINS_DIR=	${PREFIX}/lib/xmms/Input
EXTRA_CFLAGS=	`xmms-config --cflags`
EXTRA_LDFLAGS+=	`xmms-config --libs`
.endif

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -fPIC -shared \
		-I${LOCALBASE}/include -DHAVE_STDINT_H \
		${EXTRA_CFLAGS} *.c -o libmp4.so \
		-L${LOCALBASE}/lib -lfaad -lmp4ff \
		${EXTRA_LDFLAGS}

do-install:
	cd ${WRKSRC}; ${INSTALL_DATA} libmp4.so ${PLUGINS_DIR}

.include <bsd.port.post.mk>
