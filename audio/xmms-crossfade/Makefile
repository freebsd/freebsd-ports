# New ports collection makefile for:	xmms-crossfade
# Date created:			21 September 2000
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

PORTNAME=	crossfade
PORTVERSION=	0.3.14
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.eisenlohr.org/xmms-crossfade/ CENKES
PKGNAMEPREFIX=	${APP}-
DISTNAME=	xmms-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Crossfading/Gapless Plugin

LIB_DEPENDS?=	xmms.4:${PORTSDIR}/multimedia/xmms

HAS_CONFIGURE=	yes
APP?=		xmms
.if ${APP} == bmp
PORTVERSION=	0.3.12
PORTREVISION=	1
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
	@${REINPLACE_CMD} -e '/objformat=/s|aout|elf|; \
		s|dummy audacious|&2|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/libcrossfade.so ${PREFIX}/${PLUGDIR}/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
