# New ports collection makefile for:	xchadance
# Version required:	1.0
# Date created:		21 August 1998
# Whom:			issei <issei@jp.FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	xchada01
PKGNAME=	xchadance-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.jp.FreeBSD.ORG/~issei/LOCAL_PORTS/
EXTRACT_SUFX=	.lzh

MAINTAINER=	issei@jp.FreeBSD.ORG

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha

MAKEFILE=	makefile
USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	e
EXTRACT_AFTER_ARGS=

RESTRICTED=	'contains commercial character data'

post-patch:
	@cd ${WRKSRC}; \
	${PATCH} < ${WRKSRC}/xchada01.bug

post-install:
.if !defined(NOPORTOCS)
	@${MKDIR} ${PREFIX}/share/doc/xchadance
	@${INSTALL_DATA} ${WRKSRC}/README.jp ${PREFIX}/share/doc/xchadance
	@${INSTALL_DATA} ${WRKSRC}/README.eng ${PREFIX}/share/doc/xchadance
.endif

.include <bsd.port.mk>
