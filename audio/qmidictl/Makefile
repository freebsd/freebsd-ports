PORTNAME=	qmidictl
DISTVERSION=	0.9.5
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MIDI remote control application sending MIDI over UDP/IP multicast

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang gl localbase pkgconfig qt:5
GNU_CONFIGURE=	yes
USE_QT=		core gui network widgets qmake_build buildtools_build linguisttools_build
USE_GL=		gl

BINARY_ALIAS=	qmake=${QMAKE}

.include <bsd.port.mk>
