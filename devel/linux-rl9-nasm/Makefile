PORTNAME=	nasm
PORTVERSION=	2.15.03
DISTVERSIONSUFFIX=	-7.el9
CATEGORIES=	devel
MASTER_SITES=	https://mirrors.vcea.wsu.edu/rocky/9/devel/x86_64/os/Packages/:amd64

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Portable x86 assembler which uses Intel-like syntax
WWW=		https://www.nasm.us/

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64

USES=		linux:rl9
USE_LINUX_RPM=	nolib

SRC_DISTFILES=

DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
