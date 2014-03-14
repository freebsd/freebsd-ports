# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME?=	mvdsv
PORTVERSION=	0.29
PORTEPOCH=	2
CATEGORIES?=	games
MASTER_SITES=	http://qw-dev.net/attachments/download/201/
DISTNAME=	mvdsv_${PORTVERSION}-sources

MAINTAINER=	danfe@FreeBSD.org
COMMENT?=	Enhanced QuakeWorld server with multi-view demos capability

LICENSE=	GPLv2

USES=	zip

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	${OPSYS} ${ARCH:C/.*(64)/\1/}
ALL_TARGET=	${PORTNAME}
WRKSRC=		${WRKDIR}/mvdsv

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFINE_amd64=	ASM
OPTIONS_DEFAULT_i386=	ASM
OPTIONS_DEFAULT_amd64=	ASM

.if ${PORTNAME} == "mvdsv"
OPTIONS_DEFINE+=	KQUEUE
OPTIONS_DEFAULT+=	KQUEUE
.endif

KQUEUE_DESC=	Kqueue support

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MKQUEUE}
MAKE_ARGS+=	-DNOKQUEUE
.endif

.if ! ${PORT_OPTIONS:MASM}
MAKE_ARGS+=	-DWITHOUT_X86_ASM
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,gcc,${CC},' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,^inline ,,' ${WRKSRC}/source/sv_sys_unix.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
