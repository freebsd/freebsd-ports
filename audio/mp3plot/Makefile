# New ports collection makefile for:	mp3plot
# Date created:		12 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mp3plot
DISTVERSION=	0.4.0a
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://p.outlyer.net/mp3plot/files/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Mp3 bitrate plot tool

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost

GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/HAVE.*MAGICK=1/s|1|0|;/^#define HAVE.*MAGICK/s|1|0|;\
		/test.*==/s|==|=|;s/-O2//' ${WRKSRC}/configure

.include <bsd.port.mk>
