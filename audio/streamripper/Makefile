# New ports collection makefile for:	streamripper
# Date created:		6 Apr 2000
# Whom:			Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	streamripper
PORTVERSION=	1.61.17
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	streamripper

MAINTAINER=	rainer.alves@gmail.com
COMMENT=	Splits SHOUTcast stream into tracks

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad

USE_ICONV=	yes

OPTIONS=	VORBIS "Include Ogg Vorbis codec support" on

.include <bsd.port.pre.mk>

.ifdef(WITH_VORBIS)
LIB_DEPENDS+=	ogg.5:${PORTSDIR}/audio/libogg \
		vorbis.3:${PORTSDIR}/audio/libvorbis
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/streamripper
MAN1=		streamripper.1

pre-install:
		@${CHMOD} +x ${WRKSRC}/install-sh

.include <bsd.port.post.mk>
