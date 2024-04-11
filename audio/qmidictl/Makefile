PORTNAME=	qmidictl
DISTVERSION=	0.9.90
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MIDI remote control application sending MIDI over UDP/IP multicast
WWW=		https://qmidictl.sourceforge.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang gl localbase pkgconfig qt:6
GNU_CONFIGURE=	yes
USE_QT=		base svg tools:build
USE_GL=		gl opengl

BINARY_ALIAS=	qmake=${QMAKE} \
		git=false

.include <bsd.port.mk>
