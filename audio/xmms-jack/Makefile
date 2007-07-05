# New ports collection makefile for:	xmms-jack
# Date created:				13 Mar 2004
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$

PORTNAME=	jack
PORTVERSION=	0.17
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xmms-jack
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	dyeske@gmail.com
COMMENT=	XMMS plugin for jack

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		jack.0:${PORTSDIR}/audio/jack \
		samplerate.1:${PORTSDIR}/audio/libsamplerate

WRKSRC=		${WRKDIR}/xmms-jack

USE_X_PREFIX=	yes
USE_GNOME=	gtk12 gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	lib/xmms/Output/libjackout.a \
		lib/xmms/Output/libjackout.la \
		lib/xmms/Output/libjackout.so

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

post-patch:
	@${RM} -rf ${WRKSRC}/.libs
	@${RM} -rf ${WRKSRC}/autom4te.cache
	@${RM} -rf ${WRKSRC}/libjackout.la

	${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g; \
		s|-ldl||' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
