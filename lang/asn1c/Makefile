# New ports collection makefile for:	asn1c
# Date created:				10 Sep 2004
# Whom:					Lev Walkin <vlm@lionet.info>
#
# $FreeBSD$
#

PORTNAME=	asn1c
PORTVERSION=	0.9.8
CATEGORIES=	lang converters security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} 	\
		http://lionet.info/soft/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vlm@lionet.info
COMMENT=	Modern ASN.1 to C compiler

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_PERL5=	yes

MAN1=	asn1c.1 enber.1 unber.1

.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%PREFIX%%:${PREFIX}:g"

.include <bsd.port.post.mk>
