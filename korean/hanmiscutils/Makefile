# New ports collection makefile for:	hanmiscutils
# Date created:		25 Jun 2000
# Whom:			CHOI Junho <cjh@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	hanmiscutils
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	korean
MASTER_SITES=	ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	cjh@FreeBSD.ORG
COMMENT=	Collection of various Hangul-related sources

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utils/fnt2c     ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/genunihan ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/iso2euckr ${PREFIX}/bin

.include <bsd.port.mk>
