# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	openspc
PORTVERSION=	0.0.3
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	CRITICAL
PKGNAMEPREFIX=	xmms-
DISTNAME=	xmms-OpenSPC-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	An SPC player for XMMS using OpenSPC

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm \
		xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes

PLIST_FILES=	lib/xmms/Input/openspc.la \
		lib/xmms/Input/openspc.so

ONLY_FOR_ARCHS=	i386	# contains x86 assembler code

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000000
BROKEN=		does not build on FreeBSD 10.x and later
.endif

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
