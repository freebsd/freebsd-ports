# New ports collection makefile for:	mpg321
# Date created:			Mar 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpg321
PORTVERSION=	0.1.5
CATEGORIES=	audio
MASTER_SITES=	http://people.debian.org/~drew/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	naddy@mips.inka.de

LIB_DEPENDS=	ao.1:${PORTSDIR}/audio/libao
BUILD_DEPENDS=	${LOCALBASE}/lib/libmad.a:${PORTSDIR}/audio/mad

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mpg123-symlink
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		mpg321.1

.include <bsd.port.mk>
