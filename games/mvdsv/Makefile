# New ports collection makefile for:	MVDSV (+ master port for qwdtools)
# Date created:				03 Jun 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME?=	mvdsv
PORTVERSION=	0.28
PORTEPOCH=	2
CATEGORIES?=	games
MASTER_SITES=	http://qw-dev.net/attachments/download/130/
DISTNAME=	mvdsv_${PORTVERSION}-sources

MAINTAINER=	danfe@FreeBSD.org
COMMENT?=	Enhanced QuakeWorld server with multi-view demos capability

USE_ZIP=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	${OPSYS}
ALL_TARGET=	${PORTNAME}
WRKSRC=		${WRKDIR}/mvdsv-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME}

OPTIONS=	X86_ASM	"Compile with x86 assembly code" on
.if ${PORTNAME} == "mvdsv"
OPTIONS+=	KQUEUE	"Enable Kqueue support"		 on
.endif

.include <bsd.port.pre.mk>

.if defined(WITHOUT_KQUEUE)
MAKE_ARGS+=	-DNOKQUEUE
.endif

.if defined(WITHOUT_X86_ASM)
MAKE_ARGS+=	-DWITHOUT_X86_ASM
.endif

post-extract:
# Allow execution of configure script (fix permissions)
	@${CHMOD} +x ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
# Checking for presence of ${PKGMESSAGE} explicitly does not work here
.if exists(${.CURDIR}/pkg-message)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
