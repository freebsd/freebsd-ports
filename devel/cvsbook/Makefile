# New ports collection makefile for:	cvsbook
# Date created:		2002/02/28
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cvsbook
PORTVERSION=	1.21
CATEGORIES=	devel
MASTER_SITES=	http://cvsbook.red-bean.com/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	alane@FreeBSD.org

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_SUB+=	DOCSDIR=${DOCSDIR:S,${PREFIX}/,,}

do-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.pdf ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.ps ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.info* ${PREFIX}/info
	@install-info ${PREFIX}/info/cvsbook.info ${PREFIX}/info/dir

.include <bsd.port.mk>

#
#EOF
