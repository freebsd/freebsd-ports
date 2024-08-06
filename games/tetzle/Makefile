PORTNAME=	tetzle
PORTVERSION=	3.0.0
CATEGORIES=	games
MASTER_SITES=	https://gottcode.org/${PORTNAME}/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Jigsaw puzzle with tetrominoes
WWW=		https://gottcode.org/tetzle/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang desktop-file-utils qt:6 tar:bzip2
USE_QT=		base tools:build

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
