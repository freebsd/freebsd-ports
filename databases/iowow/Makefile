# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iowow
PORTVERSION=	1.0.5
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Persistent key-value database engine

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	invokes x86 assembler

USES=		cmake:outsource compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	Softmotions
USE_LDCONFIG=	yes

PORTDOCS=	Changelog README

post-patch:
	@${REINPLACE_CMD} -e '/sizeof(size_t)/d' ${WRKSRC}/src/kv/iwkv.c

.include <bsd.port.mk>
