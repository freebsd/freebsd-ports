PORTNAME=	peg-e
PORTVERSION=	1.3.3
CATEGORIES=	games
MASTER_SITES=	https://gottcode.org/${PORTNAME}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Peg elimination game
WWW=		https://gottcode.org/peg-e/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang gl qt:6 tar:bzip2
USE_QT=		base tools:build
USE_GL=		gl

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
