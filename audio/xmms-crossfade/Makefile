# New ports collection makefile for:	xmms-crossfade
# Date created:			21 September 2000
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	crossfade
PORTVERSION=	0.3.12
CATEGORIES=	audio
MASTER_SITES=	http://www.eisenlohr.org/xmms-crossfade/ CSME
PKGNAMEPREFIX=	${APP}-
DISTNAME=	xmms-${PORTNAME}-${PORTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A Crossfading/Gapless Plugin

LIB_DEPENDS?=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_GCC=	3.4+
HAS_CONFIGURE=	yes
APP?=		xmms
.if ${APP} != audacious
USE_X_PREFIX=	yes
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
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--enable-samplerate
.endif

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|aout|elf|' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/libcrossfade.so ${PREFIX}/${PLUGDIR}/
.ifndef NOPORTDOCS
	${INSTALL_DATA} -d -m 555 ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
