# Created by: Lev Walkin <vlm@lionet.info>
# $FreeBSD$

PORTNAME=	asn1c
PORTVERSION=	0.9.24
CATEGORIES=	lang converters security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://lionet.info/soft/

MAINTAINER=	vlm@lionet.info
COMMENT=	Modern ASN.1 to C compiler

GNU_CONFIGURE=	yes
USES=		perl5
SUB_FILES=	pkg-message
.if defined(.PARSEDIR)
USE_GMAKE=	yes
.endif

MAN1=	asn1c.1 enber.1 unber.1

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
