# Created by: Espen Skoglund <esk@ira.uka.de>
# $FreeBSD$

PORTNAME=	crossfade
PORTVERSION=	0.3.14
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.eisenlohr.org/xmms-crossfade/ CENKES
PKGNAMEPREFIX=	${APP}-
DISTNAME=	xmms-${PORTNAME}-${PORTVERSION}

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	Crossfading/Gapless Plugin

LIB_DEPENDS?=	xmms.4:${PORTSDIR}/multimedia/xmms

HAS_CONFIGURE=	yes
USE_CSTD=	gnu89
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

.ifndef WITHOUT_SAMPLERATE
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--enable-samplerate
.endif

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|aout|elf|; \
		s|dummy audacious|&2|g' ${WRKSRC}/configure

do-install:
	@${MKDIR} ${PREFIX}/${PLUGDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/libcrossfade.so ${PREFIX}/${PLUGDIR}/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
