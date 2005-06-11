# New ports collection makefile for:	xmms-openspc
# Date created:				11 June 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	xmms-openspc
PORTVERSION=	0.0.3
CATEGORIES=	audio
MASTER_SITES=	http://staff.xmms.org/zinx/misc/tmp/
DISTNAME=	xmms-OpenSPC-${PORTVERSION}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	An SPC player for XMMS using OpenSPC

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm \
		xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/openspc.so

ONLY_FOR_ARCHS=	i386	# contains x86 assembler code
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15

.include <bsd.port.mk>
