# New ports collection makefile for:	m4
# Version required:     1.4
# Date created:		25 October 1994
# Whom:			mr
#
# $Id: Makefile,v 1.10 1999/03/11 21:47:09 scrappy Exp $
#

DISTNAME=       m4-1.4
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	m4

MAINTAINER=	ports@FreeBSD.ORG

Y2K=		http://www.gnu.org/software/year2000.html

GNU_CONFIGURE=yes
CONFIGURE_ARGS= --program-prefix=g

post-install:
	@${MKDIR} ${PREFIX}/share/examples/gm4
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${PREFIX}/share/examples/gm4
	@install-info ${PREFIX}/info/m4.info ${PREFIX}/info/dir

.include <bsd.port.mk>
