# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pgxnclient
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Command line tool to interact with the PostgreSQL Extension Network

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python shebangfix
SHEBANG_FILES=	pgxnclient/libexec/pgxn-*
USE_PYTHON=	distutils autoplist concurrent optsuffix
NO_ARCH=	yes

.include <bsd.port.mk>
