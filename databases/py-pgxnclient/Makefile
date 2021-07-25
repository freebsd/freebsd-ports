# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>

PORTNAME=	pgxnclient
PORTVERSION=	1.3.1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Command line tool to interact with the PostgreSQL Extension Network

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils optsuffix
SHEBANG_FILES=	pgxnclient/libexec/pgxn-*
NO_ARCH=	yes

.include <bsd.port.mk>
