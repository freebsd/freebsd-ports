# $FreeBSD$

PORTNAME=	faad2
PORTVERSION=	2.7
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SFE/faac

BUILD_DEPENDS=	faad2>=2.7:${PORTSDIR}/audio/faad
RUN_DEPENDS=	faad2>=2.7:${PORTSDIR}/audio/faad

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/plugins/xmms/src

USES+=		pkgconfig
USE_BZIP2=	yes
WANT_GNOME=	yes

DESCR=		${PORTSDIR}/audio/faad/pkg-descr
PLIST_FILES=	${PLUGINS_DIR:S,^${PREFIX}/,,}/libmp4.so

.if ${PKGNAMEPREFIX} == "xmms-"
LIB_DEPENDS+=	libxmms.so:${PORTSDIR}/multimedia/xmms
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
	@${MKDIR} ${STAGEDIR}${PLUGINS_DIR}
	cd ${WRKSRC}; ${INSTALL_LIB} libmp4.so ${STAGEDIR}${PLUGINS_DIR}

.include <bsd.port.mk>
