# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	openspc
PORTVERSION=	0.0.3
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	LOCAL/ehaupt
PKGNAMEPREFIX=	xmms-
DISTNAME=	xmms-OpenSPC-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	SPC player for XMMS using OpenSPC

BUILD_DEPENDS=	nasm:devel/nasm \
		xmms:multimedia/xmms
RUN_DEPENDS=	xmms:multimedia/xmms

GNU_CONFIGURE=	yes
USES=		libtool

PLIST_FILES=	lib/xmms/Input/openspc.so

ONLY_FOR_ARCHS=	i386	# contains x86 assembler code

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 1000000
BROKEN=		does not build on FreeBSD 10.x and later
.endif

.include <bsd.port.mk>
