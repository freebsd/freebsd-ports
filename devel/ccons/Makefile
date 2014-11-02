# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ccons
PORTVERSION=	r251
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Interactive Console for the C Programming Language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	llvm-config33:${PORTSDIR}/devel/llvm33 \
		clang++33:${PORTSDIR}/lang/clang33
RUN_DEPENDS=	clang++33:${PORTSDIR}/lang/clang33
LIB_DEPENDS=	libncurses.so:${PORTSDIR}/devel/ncurses

ONLY_FOR_ARCHS=	i386 amd64
USES=		cmake
CMAKE_ARGS+=	-DLLVM_CONFIG_EXECUTABLE=${LOCALBASE}/bin/llvm-config33
CXXFLAGS+=	-fno-rtti

SUB_FILES=	ccons.sh
PLIST_FILES=	bin/ccons man/man1/ccons.1.gz \
		bin/ccons-bin

WRKSRC=	${WRKDIR}/ccons

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000054
CXXFLAGS+=	-stdlib=libc++
.endif

.if ${OSVERSION} < 900044
BROKEN=	ccons does not work on FreeBSD < 9.0-RELEASE
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ccons ${STAGEDIR}${PREFIX}/bin/ccons-bin
	@${INSTALL_SCRIPT} ${WRKDIR}/ccons.sh ${STAGEDIR}${PREFIX}/bin/ccons
	@${INSTALL_MAN} ${WRKSRC}/man/ccons.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/ccons.1

.include <bsd.port.post.mk>
