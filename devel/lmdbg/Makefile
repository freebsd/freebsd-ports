# New ports collection makefile for:	lmdbg
# Date created:				14 March 2009
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	lmdbg
PORTVERSION=	0.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Lightweight malloc debugger

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README    ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/NEWS      ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/TODO      ${DOCSDIR}
.endif

.include <bsd.port.mk>
