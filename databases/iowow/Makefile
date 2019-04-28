# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iowow
PORTVERSION=	1.3.14
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Persistent key-value database engine

LICENSE=	MIT

USES=		cmake compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	Softmotions
USE_LDCONFIG=	yes

PLIST_SUB+=	VERSION=${PORTVERSION}
PORTDOCS=	Changelog README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
