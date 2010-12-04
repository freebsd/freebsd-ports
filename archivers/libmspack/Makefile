# New ports collection makefile for:	libmspack
# Date created:				25 Nov 2004
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmspack
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.cabextract.org.uk/libmspack/
DISTNAME=	${PORTNAME}-${PORTVERSION}alpha

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	A library for Microsoft compression formats

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,$$(libdir)/pkgconfig,@prefix@/libdata/pkgconfig,g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
