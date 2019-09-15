# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	stldoc
PORTVERSION=	1.0
CATEGORIES=	lang devel
MASTER_SITES=	http://www.sgi.com/tech/stl/
DISTNAME=	STL_doc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The STL reference manual by SGI

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
