PORTNAME=	cutemaze
PORTVERSION=	1.3.6
CATEGORIES=	games
MASTER_SITES=	https://gottcode.org/${PORTNAME}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Simple, top-down game in which mazes are randomly generated
WWW=		https://gottcode.org/cutemaze/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang gettext-tools gl qt:6 tar:bzip2
USE_GL=		opengl
USE_QT=		base svg tools:build

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
