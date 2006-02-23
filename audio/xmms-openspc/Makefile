# New ports collection makefile for:	xmms-openspc
# Date created:				11 June 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	openspc
PORTVERSION=	0.0.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://critical.ch/distfiles/ \
		http://staff.xmms.org/zinx/misc/tmp/
PKGNAMEPREFIX=	xmms-
DISTNAME=	xmms-OpenSPC-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	An SPC player for XMMS using OpenSPC

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm \
		xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/openspc.la \
		lib/xmms/Input/openspc.so

ONLY_FOR_ARCHS=	i386	# contains x86 assembler code
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
