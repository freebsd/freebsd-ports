# New ports collection makefile for:	bmp-musepack
# Date Created:		12 February 2007
# Whom:			Zhen REN <bg1tpt@gmail.com>
#
# $FreeBSD$

PORTNAME=	musepack
PORTVERSION=	1.2
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://files.musepack.net/linux/plugins/
PKGNAMEPREFIX=	bmp-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	Musepack decoder for beep-media-player

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player \
		mpcdec:${PORTSDIR}/audio/libmpcdec \
		tag:${PORTSDIR}/audio/taglib

USE_BZIP2=	yes
USE_GMAKE=	yes
CPPFLAGS+=	"-I${LOCALBASE}/include"
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
USE_AUTOTOOLS=	autoconf:262 libtool:15
PLUGDIR=	lib/bmp/Input
PLUGFILE=	libbmp-mpc.so
PLIST_FILES=	${PLUGDIR}/${PLUGFILE}

do-install:
	${MKDIR} ${PREFIX}/${PLUGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/libmpc.so ${PREFIX}/${PLUGDIR}/${PLUGFILE}

.include <bsd.port.mk>
