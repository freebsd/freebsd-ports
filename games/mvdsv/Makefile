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

USE_ZIP=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	${OPSYS} ${ARCH:C/.*(64)/\1/}
MAKE_ARGS=	CC="${CC}"
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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MKQUEUE}
MAKE_ARGS+=	-DNOKQUEUE
.endif

.if ! ${PORT_OPTIONS:MASM}
MAKE_ARGS+=	-DWITHOUT_X86_ASM
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,^inline ,,' ${WRKSRC}/source/sv_sys_unix.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
# Checking for presence of ${PKGMESSAGE} explicitly does not work here
.if exists(${.CURDIR}/pkg-message)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
