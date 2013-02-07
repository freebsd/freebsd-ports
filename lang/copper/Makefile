# Created by: gahr
# $FreeBSD$

PORTNAME=	copper
PORTVERSION=	1.6
CATEGORIES=	lang
MASTER_SITES=	http://tibleiz.net/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Another experimental programming language

BUILD_DEPENDS=	llc:${PORTSDIR}/devel/llvm

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
USE_LINUX=	f10
MAKE_ARGS+=	BACKEND=llvm
WRKSRC=		${WRKDIR}/${PKGNAME}

PLIST_FILES=	bin/copper-llvm

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
ALL_TARGET=	boot64 all
.else
ALL_TARGET=	all
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; \
	    s|^CC|#CC|; \
	    s|x86_64|amd64|; \
	    s|g++|${CXX}|; \
	    s|-ldl||g; \
	    s|^LFLAGS=|LFLAGS=-L${LOCALBASE}/lib|' \
	    ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
