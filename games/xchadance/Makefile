# New ports collection makefile for:	xchadance
# Date created:		21 August 1998
# Whom:			issei <issei@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xchadance
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.mk.bsdclub.org/pub/FreeBSD/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	motoyuki
DISTFILES=	xchada01.lzh

MAINTAINER=	motoyuki@FreeBSD.org
COMMENT=	Display a dancing girl "ChaCha."

EXTRACT_DEPENDS=lha:${PORTSDIR}/archivers/lha

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
