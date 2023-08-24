PORTNAME=	tipp10
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.0
CATEGORIES=	german

MAINTAINER=	nick.lott@gmail.com
COMMENT=	10-finger touch typing learning program
WWW=		https://www.tipp10.com

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake sqlite qt:6 gl
USE_GITLAB=	yes
USE_QT=		base sqldriver-sqlite:run tools:build multimedia
USE_GL=		gl opengl

.include <bsd.port.mk>
