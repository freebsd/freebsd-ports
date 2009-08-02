# New ports collection makefile for:	xmms-jack
# Date created:				13 Mar 2004
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$

PORTNAME=	xmms-jack
PORTVERSION=	0.19
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS plugin for jack

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		jack.0:${PORTSDIR}/audio/jack \
		samplerate.1:${PORTSDIR}/audio/libsamplerate

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	lib/xmms/Output/libjackout.so

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|-ldl||g' ${WRKSRC}/configure

do-install:
	cd ${WRKSRC}/.libs \
		&& ${INSTALL_DATA} libjackout.so ${PREFIX}/lib/xmms/Output

.include <bsd.port.post.mk>
