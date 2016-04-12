# Created by: gahr
# $FreeBSD$

PORTNAME=	codelite
PORTVERSION=	9.1
CATEGORIES=	editors devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source IDE for C/C++

LICENSE=	GPLv2+

RUN_DEPENDS=	xterm:x11/xterm

USE_GITHUB=	yes
GH_ACCOUNT=	eranif

USES=		cmake:outsource compiler:c++11-lib dos2unix execinfo gettext \
		shebangfix sqlite
DOS2UNIX_GLOB=	*.cpp *.txt
SHEBANG_FILES=	Runtime/codelite_xterm
bash_CMD=	/bin/sh
USE_WX=		3.0
CMAKE_ARGS=	-DENABLE_LLDB:STRING=0 \
		-DPREFIX:STRING="${PREFIX}" \
		-DIS_FREEBSD:STRING=1 \
		-DCL_WX_CONFIG:STRING="${WX_CONFIG:T}"
USE_LDCONFIG=	${PREFIX}/lib/codelite
INSTALLS_ICONS=	yes

CXXFLAGS+=	${EXECINFO_CPPFLAGS}
LDFLAGS+=	${EXECINFO_LDFLAGS}

OPTIONS_DEFINE=		CSCOPE SFTP
OPTIONS_RADIO=		CLANG
OPTIONS_RADIO_CLANG=	CLANG34 CLANG35 CLANG36 CLANG37
OPTIONS_SUB=		yes

CLANG_DESC=		Clang code-completion
CLANG34_DESC=		Clang 3.4.x
CLANG34_BUILD_DEPENDS=	clang34>0:lang/clang34
CLANG34_RUN_DEPENDS=	clang34>0:lang/clang34
CLANG35_DESC=		Clang 3.5.x
CLANG35_BUILD_DEPENDS=	clang35>0:lang/clang35
CLANG35_RUN_DEPENDS=	clang35>0:lang/clang35
CLANG36_DESC=		Clang 3.6.x
CLANG36_BUILD_DEPENDS=	clang36>0:lang/clang36
CLANG36_RUN_DEPENDS=	clang36>0:lang/clang36
CLANG37_DESC=		Clang 3.7.x
CLANG37_BUILD_DEPENDS=	clang37>0:lang/clang37
CLANG37_RUN_DEPENDS=	clang37>0:lang/clang37
CSCOPE_DESC=		CScope integration
CSCOPE_RUN_DEPENDS=	cscope:devel/cscope
SFTP_DESC=		Secure FTP support via libssh
SFTP_LIB_DEPENDS=	libssh.so:security/libssh
SFTP_CMAKE_OFF=		-DENABLE_SFTP:STRING=0
SFTP_USES=		localbase

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLANG34} || ${PORT_OPTIONS:MCLANG35} || ${PORT_OPTIONS:MCLANG36}
CMAKE_ARGS+=	-DENABLE_CLANG:STRING=1
.else
CMAKE_ARGS+=	-DENABLE_CLANG:STRING=0
.endif

post-patch:
#	Use the correct wx-config
	@${REINPLACE_CMD} -e \
		'/ IS_FREEBSD/s|^|#| ; \
		 / CL_WX_CONFIG/s|^|#| ; \
		 / -Wno-/s|^|#| ; \
		 / -O2/s|^|#| ; \
		 s|"-s"|""|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|"-lkvm"|"-lkvm -lutil"| ; \
		 s|share/man|man|' \
		${WRKSRC}/LiteEditor/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|"-lutil"|"-lkvm -lutil"|' \
		${WRKSRC}/codelite_terminal/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		'/ADDITIONAL_LIBRARIES/s|""|"-lexecinfo"|' \
		${WRKSRC}/sdk/codelite_cppcheck/CMakeLists.txt

post-patch-CLANG34-on:
	@${REINPLACE_CMD} -e \
		's|/usr/lib/llvm-.*/|${LOCALBASE}/llvm34/|' \
		${WRKSRC}/cmake/Modules/FindLibClang.cmake

post-patch-CLANG35-on:
	@${REINPLACE_CMD} -e \
		's|/usr/lib/llvm-.*/|${LOCALBASE}/llvm35/|' \
		${WRKSRC}/cmake/Modules/FindLibClang.cmake

post-patch-CLANG36-on:
	@${REINPLACE_CMD} -e \
		's|/usr/lib/llvm-.*/|${LOCALBASE}/llvm36/|' \
		${WRKSRC}/cmake/Modules/FindLibClang.cmake

.include <bsd.port.mk>
