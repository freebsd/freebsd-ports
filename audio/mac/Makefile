# New ports collection makefile for:   mac
# Date created:        8 Aug 2004
# Whom:                dieringe
#
# $FreeBSD$
#

PORTNAME=	mac
PORTVERSION=	3.99.4.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mac-port
DISTNAME=	${PORTNAME}-3.99-u4-b4

MAINTAINER=	dieringe@zedat.fu-berlin.de
COMMENT=	Monkey's Audio lossless audio (de)compressor

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-backward

INSTALLS_SHLIB=	yes

# does not compile on sparc64
NOT_FOR_ARCHS=	sparc64

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not compile on 4.x due to missing multibyte string functions in libc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-s -O3||' ${WRKSRC}/configure

.include <bsd.port.post.mk>
