# New ports collection makefile for:	joe-devel
# Date created:		25 Jul 2001
# Whom:			dwcjr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	joe-devel
PORTVERSION=	2.9.6
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	joe-editor
DISTNAME=	joe-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	petef@databits.net

MAN1=		joe.1

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/joe
	${INSTALL_DATA} ${WRKSRC}/INFO ${WRKSRC}/README ${PREFIX}/share/doc/joe
	${INSTALL_DATA} ${WRKSRC}/LIST ${PREFIX}/share/doc/joe/CommandList
.endif

.include <bsd.port.mk>
