# New ports collection makefile for:    napster
# Date created:         Thu Nov 18 01:07:00 PST 1999
# Whom:                 dburr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	nap
PORTVERSION=	1.4.5
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nap

MAINTAINER=	petef@databits.net

GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/nap
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nap
.endif

.include <bsd.port.mk>
