# Created by: Naram Qashat <cyberbotx@cyberbotx.com>
# $FreeBSD$

PORTNAME=	sexyspc
PORTVERSION=	0.5.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF
PKGNAMEPREFIX=	xmms-

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	An SPC plugin for XMMS based on the SNESAPU emulation core

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm \
		xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/libsexyspc.a \
		lib/xmms/Input/libsexyspc.la \
		lib/xmms/Input/libsexyspc.so

ONLY_FOR_ARCHS=	i386	# contains x86 assembler code
USE_LDCONFIG=	yes
NO_STAGE=	yes
GNU_CONFIGURE=	yes
USES=		gmake

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.Inc

.include <bsd.port.mk>
