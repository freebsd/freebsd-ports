# Created by: gahr
# $FreeBSD$

PORTNAME=	codelite
PORTVERSION=	9.1
PORTREVISION=	1
CATEGORIES=	editors devel

MAINTAINER=	mokhi64@gmail.com
COMMENT=	Open Source IDE for C/C++

LICENSE=	GPLv2+

RUN_DEPENDS=	xterm:x11/xterm

USE_GITHUB=	yes
GH_ACCOUNT=	eranif

USES=		cmake:outsource compiler:c++11-lib dos2unix execinfo gettext \
		pathfix shebangfix sqlite
DOS2UNIX_GLOB=	*.cpp *.txt
SHEBANG_FILES=	Runtime/codelite_xterm
bash_CMD=	/bin/sh
USE_WX=		3.0
CMAKE_ARGS=	-DPREFIX:STRING="${PREFIX}" \
		-DIS_FREEBSD:STRING=1 \
		-DCL_WX_CONFIG:STRING="${WX_CONFIG:T}"
USE_LDCONFIG=	${PREFIX}/lib/codelite
INSTALLS_ICONS=	yes

CXXFLAGS+=	${EXECINFO_CPPFLAGS}
LDFLAGS+=	${EXECINFO_LDFLAGS}

OPTIONS_DEFINE=		CSCOPE SFTP
OPTIONS_RADIO=		CLANG
OPTIONS_SUB=		yes

CSCOPE_DESC=		CScope integration
CSCOPE_RUN_DEPENDS=	cscope:devel/cscope
SFTP_DESC=		Secure FTP support via libssh
SFTP_LIB_DEPENDS=	libssh.so:security/libssh
SFTP_CMAKE_OFF=		-DENABLE_SFTP:STRING=0
SFTP_USES=		localbase

CLANG_DESC=		Clang code-completion

.for v in 34 35 36 37 38
OPTIONS_RADIO_CLANG+=	CLANG$v
CLANG$v_DESC=		Clang ${v:C/(.)(.)/\1.\2.x/}
CLANG$v_BUILD_DEPENDS=	clang$v>0:lang/clang$v
CLANG$v_RUN_DEPENDS=	clang$v>0:lang/clang$v

post-patch-CLANG$v-on:
	@${REINPLACE_CMD} -e \
		's|/usr/lib/llvm-.*/|${LOCALBASE}/llvm$v/|' \
		${WRKSRC}/cmake/Modules/FindLibClang.cmake \
		${WRKSRC}/cmake/Modules/FindLibLLDB.cmake
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLANG*}
CMAKE_ARGS+=	-DENABLE_LLDB:STRING=1 -DENABLE_CLANG:STRING=1
.else
CMAKE_ARGS+=	-DENABLE_LLDB:STRING=0 -DENABLE_CLANG:STRING=0
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
	@${REINPLACE_CMD} -e \
		's|/bin/grep|/usr/bin/grep|' \
		${WRKSRC}/cmake/Modules/FindLibClang.cmake

.include <bsd.port.mk>
