# Created by: Espen Skoglund <esk@ira.uka.de>
# $FreeBSD$

PORTNAME=	crossfade
PORTVERSION=	0.3.14
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.eisenlohr.org/xmms-crossfade/ CENKES
PKGNAMEPREFIX=	${APP}-
DISTNAME=	xmms-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Crossfading/Gapless Plugin

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-03-23

LIB_DEPENDS?=	libxmms.so:${PORTSDIR}/multimedia/xmms

HAS_CONFIGURE=	yes
USE_CSTD=	gnu89
USES=		pkgconfig

APP?=		xmms
.if ${APP} == bmp
PORTVERSION=	0.3.12
PORTREVISION=	3
.endif
PLUGDIR?=	lib/${APP}/Output
PORTDOCS=	README
PLIST_FILES=	${PLUGDIR}/libcrossfade.so
DOCSDIR?=	${PREFIX}/share/doc/${UNIQUENAME}
CONFIGURE_ARGS+=	--enable-player=${APP}

OPTIONS_DEFINE=	DOCS SAMPLERATE
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate
SAMPLERATE_CPPFLAGS=	-I${LOCALBASE}/include
SAMPLERATE_LDFLAGS=		-L${LOCALBASE}/lib
SAMPLERATE_CONFIGURE_ENABLE=	samplerate

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|aout|elf|; \
		s|dummy audacious|&2|g' ${WRKSRC}/configure

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PLUGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/libcrossfade.so ${STAGEDIR}${PREFIX}/${PLUGDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
