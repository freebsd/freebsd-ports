# New ports collection makefile for:	flac
# Date created:		Mar 18, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flac
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	naddy@FreeBSD.org

LIB_DEPENDS=	ogg.4:${PORTSDIR}/audio/libogg

.if defined(WITH_XMMS)
BUILD_DEPENDS+=	xmms-config:${PORTSDIR}/audio/xmms
LIB_DEPENDS+=	xmms.3:${PORTSDIR}/audio/xmms
PLIST_SUB=	XMMS=""
.else
CONFIGURE_ENV+=	XMMS_CONFIG=/usr/bin/false	# must be absolute path
PLIST_SUB=	XMMS="@comment "
.endif

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

GNU_CONFIGURE=	yes
CONFIGURE_TARGET= --target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
CONFIGURE_ARGS= --with-ogg=${LOCALBASE} \
		--enable-sse --enable-3dnow
CONFIGURE_ENV=	CONFIG_SHELL=${SH}

.if defined(NOPORTDOCS)
MAKE_ENV=	DOC=""
.else
MAKE_ENV=	DOC=doc
.endif

INSTALLS_SHLIB=	yes
MAN1=		flac.1

.include <bsd.port.mk>
