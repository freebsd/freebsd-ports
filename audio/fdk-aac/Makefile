# Created by:	Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fdk-aac
PORTVERSION=	0.1.2
CATEGORIES=	audio
MASTER_SITES=	SF/opencore-amr/${PORTNAME}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Port of the Fraunhofer FDK AAC Codec Library

NOT_FOR_ARCHS=		sparc64
NOT_FOR_ARCHS_REASON=	not yet ported to this architecture

LICENSE=	FRAUNHOFER_FDK_AAC
LICENSE_NAME=	Software License for The Fraunhofer FDK AAC Codec Library for Android
LICENSE_FILE=	${WRKSRC}/NOTICE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-lm"

post-patch:
	@${REINPLACE_CMD} -E -e \
	's|^pkgconfigdir = .*|pkgconfigdir = $$(prefix)/libdata/pkgconfig|g' \
	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
