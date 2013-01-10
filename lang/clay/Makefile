# New ports collection makefile for: clay
# Date created: 2012-01-24
# Whom: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	clay
PORTVERSION=	0.1.2
CATEGORIES=	lang
MASTER_SITES=	https://github.com/jckarter/${PORTNAME}/tarball/v${PORTVERSION}/
DISTNAME=	jckarter-${PORTNAME}-v${PORTVERSION}-0-g${GITVERSION}

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	A language designed for generic programming

LICENSE=	BSD

BUILD_DEPENDS=	llvm31>=3.1:${PORTSDIR}/devel/llvm31

OPTIONS_DEFINE=		BINDGEN
BINDGEN_DESC=		Build with binding generator
OPTIONS_DEFAULT=	BINDGEN

GITVERSION=	751ebe3
FETCH_ARGS=	-pRr
WRKSRC=		${WRKDIR}/jckarter-${PORTNAME}-${GITVERSION}

ONLY_FOR_ARCHS=	i386 amd64

USE_CMAKE=	yes
CMAKE_ARGS+=	-G "Unix Makefiles" -DBUILD_FIX=false

CC=		clang
CXX=		clang++

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MBINDGEN}
PLIST_SUB+=	BINDGEN=""
.else
PLIST_SUB+=	BINDGEN="@comment "
CMAKE_ARGS+=	-DBUILD_BINDGEN=false
.endif

.if ${OSVERSION} < 900044 || ${PORT_OPTIONS:MBINDGEN}
BUILD_DEPENDS+=	clang31>=3.1:${PORTSDIR}/lang/clang31
RUN_DEPENDS+=	clang31>=3.1:${PORTSDIR}/lang/clang31
.endif

.if defined(NOPORTDOCS)
pre-configure:
	${REINPLACE_CMD} \
	    -e 's|install(DIRECTORY doc/ DESTINATION share/doc/clay)||' \
	    ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
