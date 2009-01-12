# Ports collection Makefile for:	ljcharm
# Date created:				2003-02-26
# Whom:					schmidtcarl@earthlink.net
#
# $FreeBSD$
#

PORTNAME=	charm
PORTVERSION=	1.9.1
CATEGORIES=	deskutils net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	ljcharm

MAINTAINER=	seawolf@marinewolf.net
COMMENT=	A menu-driven python-based livejournal client

MAN1=charm.1
MAN5=charmrc.5

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	1.9.1

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/CHANGES.charm ${DOCSDIR}/CHANGES
	${INSTALL_DATA} ${WRKSRC}/README.charm ${DOCSDIR}/README
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.charmrc ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
