# New ports collection makefile for:	mpg321
# Date created:			Mar 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpg321
PORTVERSION=	0.2.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= mpg321

MAINTAINER=	naddy@FreeBSD.org

LIB_DEPENDS=	ao.3:${PORTSDIR}/audio/libao \
		mad.1:${PORTSDIR}/audio/mad

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mpg123-symlink
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		mpg321.1

.include <bsd.port.mk>
