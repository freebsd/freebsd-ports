# New ports collection makefile for:   kmpg
# Date created:        24 May 1999
# Whom:                Oscar Bonilla <obonilla@fisicc-ufm.edu>
#
# $FreeBSD$
#

PORTNAME=	kmp3
PORTVERSION=	1.0
CATEGORIES=	audio kde
MASTER_SITES=	http://www.kmp3.org/tarballs/

MAINTAINER=	mb@imp.ch

LIB_DEPENDS=	QwSpriteField.7:${PORTSDIR}/converters/kdesupport11

USE_KDELIBS_VER=1
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/kmp3

pre-configure:
	${PERL} -pi.orig -e 's|-O4 -m486|${CFLAGS}|' ${WRKSRC}/src/mpeg/configure

.include <bsd.port.mk>
