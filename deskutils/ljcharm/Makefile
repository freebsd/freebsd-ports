# Ports collection Makefile for:	ljcharm
# Date created:				2003-02-26
# Whom:					schmidtcarl@earthlink.net
#
# $FreeBSD$
#

PORTNAME=	charm
PORTVERSION=	1.3.0
CATEGORIES=	deskutils net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ljcharm

MAINTAINER=	schmidtcarl@earthlink.net
COMMENT=	A menu-driven python-based livejournal client

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/charm ${PREFIX}/bin

	@${MKDIR} ${PREFIX}/share/examples/charm
	@${INSTALL_DATA} ${WRKSRC}/sample.charmrc ${PREFIX}/share/examples/charm

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/charm
	@${INSTALL_DATA} ${WRKSRC}/CHANGES.charm ${PREFIX}/share/doc/charm/CHANGES
	@${INSTALL_DATA} ${WRKSRC}/README.charm ${PREFIX}/share/doc/charm/README
.endif

.include <bsd.port.mk>
