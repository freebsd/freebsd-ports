# New ports collection makefile for:   jday
# Date created:                2000-11-27
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	jday
PORTVERSION=	1.2
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jday

MAINTAINER=	naddy@FreeBSD.org

GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jday
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/jday
.endif

.include <bsd.port.mk>
