# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	atr3d
PORTVERSION=	0.6
PORTREVISION=	18
CATEGORIES=	games
MASTER_SITES=	http://rodrigo.osorio.free.fr/freebsd/distfiles/
DISTNAME=	${PORTNAME}_source_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D asteroids-like multiplayer game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		autoreconf gl gmake perl5 tar:tgz xorg
USE_GL=		glut glu
USE_XORG=	xmu xi x11
USE_PERL5=	build
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LLD_UNSAFE=	yes

OPTIONS_DEFINE=	OPENAL
OPTIONS_DEFAULT=OPENAL

OPENAL_USES=	openal:alut
OPENAL_CONFIGURE_ENABLE=	sound

pre-patch:
	@${REINPLACE_CMD} -e 's|-lopenal|& -lalut|' ${WRKSRC}/Makefile.am

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
