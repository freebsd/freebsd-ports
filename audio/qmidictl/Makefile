# $FreeBSD$

PORTNAME=	qmidictl
DISTVERSION=	0.5.3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MIDI remote control application sending MIDI over UDP/IP multicast

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl gmake localbase pkgconfig qt:5
GNU_CONFIGURE=	yes
USE_QT=		core gui widgets qmake_build buildtools_build
USE_GL=		gl

.include <bsd.port.mk>
