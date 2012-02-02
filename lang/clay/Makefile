# New ports collection makefile for: clay
# Date created: 2012-01-24
# Whom: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	clay
PORTVERSION=	0.1.0
CATEGORIES=	lang
MASTER_SITES=	https://github.com/jckarter/${PORTNAME}/tarball/v${PORTVERSION}/
DISTNAME=	jckarter-${PORTNAME}-v${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	A language designed for generic programming

LICENSE=	BSD

BUILD_DEPENDS=	llvm>=3.0:${PORTSDIR}/devel/llvm

GITVERSION=	0dcc5de
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/jckarter-${PORTNAME}-${GITVERSION}

ONLY_FOR_ARCHS=	i386 amd64

USE_CMAKE=	yes
CMAKE_ARGS+=	-G "Unix Makefiles" -DBUILD_FIX=false

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CC=		clang
CXX=		clang++
.endif

.if ${OSVERSION} < 900044
BUILD_DEPENDS+=	clang>=3.0:${PORTSDIR}/lang/clang
RUN_DEPENDS+=	clang>=3.0:${PORTSDIR}/lang/clang
.endif

.if defined(NOPORTDOCS)
pre-configure:
	${REINPLACE_CMD} \
	    -e 's|install(DIRECTORY doc/ DESTINATION share/doc/clay)||' \
	    ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
