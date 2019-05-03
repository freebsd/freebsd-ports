# $FreeBSD$

PORTNAME=		fastp
DISTVERSIONPREFIX=	v
DISTVERSION=		0.20.0
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ultra-fast all-in-one FASTQ preprocessor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gmake
USE_GITHUB=	yes

GH_ACCOUNT=	OpenGene

ALL_TARGET=	fastp
INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/fastp

.include <bsd.port.pre.mk>

# Force newer compiler on platforms using GCC 4.2 as base
.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
