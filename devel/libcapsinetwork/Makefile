# New ports collection makefile for:	libcapsinetwork
# Date created:				11 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	libcapsinetwork
PORTVERSION=	0.0.13
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	petef@FreeBSD.org

INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e 's!CC!CXX!g; s!CXX=!CXX?=!; s!CFLAGS=!CFLAGS+=!; \
		s!/usr/local!${PREFIX}!' ${WRKSRC}/Makefile

.include <bsd.port.mk>
