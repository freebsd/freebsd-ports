# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmspack
PORTVERSION=	0.5
PORTREVISION=	0
CATEGORIES=	archivers
MASTER_SITES=	http://www.cabextract.org.uk/libmspack/
DISTNAME=	${PORTNAME}-${PORTVERSION}alpha

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Library for Microsoft compression formats

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pathfix
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} 's,-Wno-unused-result,,' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
