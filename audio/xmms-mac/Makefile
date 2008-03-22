# New ports collection makefile for:	xmms-mac
# Date Created:				23 February 2005
# Whom:					<arundel@h3c.de>
#
# $FreeBSD$

PORTNAME=	mac
PORTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	CENKES
PKGNAMEPREFIX=	xmms-
DISTNAME=	xmms-${PORTNAME}-${PORTVERSION}

MAINTAINER=	arundel@h3c.de
COMMENT=	Monkey's Audio Codec non-win32 port

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		mac.2:${PORTSDIR}/audio/mac

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	CPPFLAGS="${CPPFLAGS}"
USE_AUTOTOOLS=	autoconf:261
CPPFLAGS+=	"-I${LOCALBASE}/include"
USE_LDCONFIG=	yes

PLIST_FILES=	lib/xmms/Input/libxmms-mac.so

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/aclocal.m4

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libxmms-mac.so ${PREFIX}/lib/xmms/Input

.include <bsd.port.mk>
