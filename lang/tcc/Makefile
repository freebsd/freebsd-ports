# $FreeBSD$

PORTNAME=	tcc
PORTVERSION=	0.9.25
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	SAVANNAH/tinycc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny C Compiler

LICENSE=	LGPL21

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	i386
#ONLY_FOR_ARCHS=	i386 amd64 arm alpha mips powerpc

CONFLICTS=	TenDRA-*

USES=		perl5
USE_BZIP2=	yes
USE_PERL5=	build
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --cc="${CC}"
MAKE_ARGS=	CONFIG_NOLDL=1

MAN1=		tcc.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS)
MAKE_ARGS+=	NOPORTDOCS=1
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif

.if ${CC:T:M*clang*} || ${OSVERSION} >= 1000024
CFLAGS+=	-fheinous-gnu-extensions
.endif

.include <bsd.port.post.mk>
