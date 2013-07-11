# Created by: gahr
# $FreeBSD$

PORTNAME=	codelite
DISTVERSION=	5.1
PORTREVISION=	1
CATEGORIES=	editors devel
MASTER_SITES=	SF/${PORTNAME}/Releases/${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-gtk.src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An Open Source IDE for C/C++

LICENSE=	GPLv2

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	xterm:${PORTSDIR}/x11/xterm

OPTIONS_DEFINE=	CSCOPE CLANG

CSCOPE_DESC=	CScope integration
CLANG_DESC=	Clang code-completion

USE_WX=		2.9
WX_UNICODE=	yes
USE_DOS2UNIX=	*.cpp
USES=		gettext cmake:outsource
USE_LDCONFIG=	lib/codelite
CMAKE_ARGS+=	-DIS_FREEBSD=1 \
		-DPREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SVN_REVISION=	6213

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCSCOPE}
RUN_DEPENDS+=	cscope:${PORTSDIR}/devel/cscope
.endif

.if ${PORT_OPTIONS:MCLANG}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libclang.so:${PORTSDIR}/lang/clang-devel
RUN_DEPENDS+=	${LOCALBASE}/lib/libclang.so:${PORTSDIR}/lang/clang-devel
PLIST_SUB+=	CLANG=""
CMAKE_ARGS+=	-DENABLE_CLANG=1
.else
PLIST_SUB+=	CLANG="@comment "
CMAKE_ARGS+=	-DENABLE_CLANG=0
.endif

post-patch:
#	Use the correct wx-config
	${REINPLACE_CMD} -e \
	    's|wx-config|${WX_CONFIG}|; \
	     s|%%LOCALBASE%%|${LOCALBASE}|g; \
	     /IS_FREEBSD/s|0|1|' \
	    ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|$${cur_rev}|${SVN_REVISION}|' \
	    ${WRKSRC}/le_makerevision.sh

.include <bsd.port.mk>
