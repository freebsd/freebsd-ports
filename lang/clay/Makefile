# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	clay
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://github.com/jckarter/${PORTNAME}/tarball/v${PORTVERSION}/
DISTNAME=	jckarter-${PORTNAME}-v${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	Language designed for generic programming

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	llvm-config32:${PORTSDIR}/devel/llvm32 \
		clang32:${PORTSDIR}/lang/clang32
RUN_DEPENDS=	clang32:${PORTSDIR}/lang/clang32

OPTIONS_DEFINE=		BINDGEN
BINDGEN_DESC=		Build with binding generator (broken on 10.0+)

GITVERSION=	751ebe3
PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/jckarter-${PORTNAME}-${GITVERSION}

ONLY_FOR_ARCHS=	i386 amd64

USES=		cmake
CMAKE_ARGS+=	-G "Unix Makefiles" -DBUILD_FIX=false

CC=		clang32
CXX=		clang++32

OPTIONS_SUB=	yes
BINDGEN_CMAKE_OFF=	-DBUILD_BINDGEN=false

.include <bsd.port.mk>
