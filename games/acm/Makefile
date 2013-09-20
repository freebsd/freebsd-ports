# Created by: joerg
# $FreeBSD$

PORTNAME=	acm
PORTVERSION=	5.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.websimulations.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A flight simulator for X11

LICENSE=	GPLv2

USES=		perl5
USE_XORG=	x11
GNU_CONFIGURE=	yes
USE_PERL5=	build

MAN6=		acm.6

NO_STAGE=	yes
.include <bsd.port.pre.mk>

# Include sound support (Use network audio server (nas))
.if defined(WITH_SOUND) || (exists(${PREFIX}/lib/libaudio.a) \
	&& !defined(WITHOUT_SOUND))
LIB_DEPENDS+=	audio.2:${PORTSDIR}/audio/nas
.endif

.include <bsd.port.post.mk>
