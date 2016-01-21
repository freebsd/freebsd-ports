# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME?=	mvdsv
PORTVERSION=	0.30
DISTVERSIONPREFIX=	v
PORTEPOCH=	2
CATEGORIES?=	games

MAINTAINER=	danfe@FreeBSD.org
COMMENT?=	Enhanced QuakeWorld server with multi-view demos capability

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	deurk

BUILD_WRKSRC?=	${WRKSRC}/build/make
MAKEFILE=	Makefile.BSD
MAKE_ARGS=	UNAME=${OPSYS}

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFINE_amd64=	ASM
OPTIONS_DEFAULT_i386=	ASM
OPTIONS_DEFAULT_amd64=	ASM

.if ${PORTNAME} == mvdsv
OPTIONS_DEFINE+=	KQUEUE
OPTIONS_DEFAULT+=	KQUEUE
.endif

KQUEUE_DESC=	Kqueue support

KQUEUE_MAKE_ARGS_OFF=	-DNOKQUEUE
ASM_MAKE_ARGS_OFF=	-DWITHOUT_X86_ASM
OPTIMIZED_CFLAGS_MAKE_ARGS=	-DWITH_OPTIMIZED_CFLAGS

post-patch:
	@${REINPLACE_CMD} -e 's,^inline ,,' ${WRKSRC}/src/sv_sys_unix.c
	@${REINPLACE_CMD} -e '/#include/s,/source,/src,' \
		${WRKSRC}/tools/qwdtools/source/defs.h

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
