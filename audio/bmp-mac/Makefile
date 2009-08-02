# New ports collection makefile for:	bmp-mac
# Date Created:		17 January 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mac
PORTVERSION=	0.1.1
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	CENKES
PKGNAMEPREFIX=	bmp-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monkey's Audio Codec non-win32 port

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player \
		mac.2:${PORTSDIR}/audio/mac

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
USE_AUTOTOOLS=	autoconf:262 libtool:22
CPPFLAGS+=	"-I${LOCALBASE}/include"
PLUGDIR=	lib/bmp/Input
PLUGFILE=	lib${PKGNAMEPREFIX}${PORTNAME}.so
PLIST_FILES=	${PLUGDIR}/${PLUGFILE}

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/${PLUGFILE} ${PREFIX}/${PLUGDIR}/

.include <bsd.port.mk>
