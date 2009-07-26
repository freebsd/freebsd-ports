# New ports collection makefile for:	xmms-sexyspc
# Date created:				5 August 2007
# Whom:					Naram Qashat <cyberbotx@cyberbotx.com>
#
# $FreeBSD$
#

PORTNAME=	sexyspc
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF
PKGNAMEPREFIX=	xmms-

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	An SPC plugin for XMMS based on the SNESAPU emulation core

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm \
		xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/libsexyspc.a \
		lib/xmms/Input/libsexyspc.la \
		lib/xmms/Input/libsexyspc.so

BROKEN=		fails to build

ONLY_FOR_ARCHS=	i386	# contains x86 assembler code
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.Inc

.include <bsd.port.mk>
