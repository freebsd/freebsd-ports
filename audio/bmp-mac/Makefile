# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mac
PORTVERSION=	0.1.1
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	CENKES
PKGNAMEPREFIX=	bmp-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monkey's Audio Codec non-win32 port

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player \
		mac.2:${PORTSDIR}/audio/mac

USES=		gmake
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf libtool
CPPFLAGS+=	"-I${LOCALBASE}/include"
PLUGDIR=	lib/bmp/Input
PLUGFILE=	lib${PKGNAMEPREFIX}${PORTNAME}.so
PLIST_FILES=	${PLUGDIR}/${PLUGFILE}

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

do-install:
	@${MKDIR} ${PREFIX}/${PLUGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/${PLUGFILE} ${PREFIX}/${PLUGDIR}/

.include <bsd.port.mk>
