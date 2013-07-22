# Created by: yinjieh
# $FreeBSD$

PORTNAME=	ggz-kde-client
PORTVERSION=	${GGZ_VERSION}
PORTREVISION=	5
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GGZ Gaming Zone - KDE Client

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

GNU_CONFIGURE=	yes
USES=		gmake
USE_KDELIBS_VER=	3
USE_GGZ=	client

MAN6=		compcal.6 ggzap.6 keepalivecontrol.6 \
		kggz.6 kgrubby.6 shadowbridge.6

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}| ; s|echo aout|echo elf|' ${WRKSRC}/configure

.include "${.CURDIR}/../libggz/bsd.ggz.mk"
.include <bsd.port.mk>
