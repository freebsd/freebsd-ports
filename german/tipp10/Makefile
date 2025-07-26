PORTNAME=	tipp10
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.4
CATEGORIES=	german education

MAINTAINER=	nick.lott@gmail.com
COMMENT=	10-finger touch typing learning program
WWW=		https://www.tipp10.com/ \
		https://gitlab.com/tipp10/tipp10/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake gl qt:6 sqlite
USE_GITLAB=	yes
USE_GL=		gl opengl
USE_QT=		base multimedia sqldriver-sqlite:run tools:build

.include <bsd.port.mk>
