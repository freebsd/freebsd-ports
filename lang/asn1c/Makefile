# New ports collection makefile for:	asn1c
# Date created:				10 Sep 2004
# Whom:					Lev Walkin <vlm@lionet.info>
#
# $FreeBSD$
#

PORTNAME=	asn1c
PORTVERSION=	0.9.21
CATEGORIES=	lang converters security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://lionet.info/soft/


MAINTAINER=	vlm@lionet.info
COMMENT=	Modern ASN.1 to C compiler

GNU_CONFIGURE=	yes
USE_PERL5=	yes
SUB_FILES=	pkg-message

MAN1=	asn1c.1 enber.1 unber.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
