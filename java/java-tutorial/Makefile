# New ports collection makefile for:	JDK tutorial
# Version required:	1.1.7
# Date created:		Tue Mar 23 10:18:20 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $Id: Makefile,v 1.3 1999/05/05 15:23:20 fenner Exp $
#

DISTNAME=	tutorial
PKGNAME=	jdk-tutorial-1.1.7
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.javasoft.com/docs/

MAINTAINER=	martti.kuparinen@ericsson.com

WRKSRC=		${WRKDIR}
RESTRICTED=	"This software is under license and export control."
NO_BUILD=	yes
PKGMESSAGE= ${WRKDIR}/MESSAGE

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/jdk1.1.7/docs/books/tutorial
	(cd ${WRKSRC} && ${TAR} -cf - * ) \
		| (cd ${PREFIX}/jdk1.1.7/docs/books/tutorial && ${TAR} -xf -)
	@${SED} s+!!PREFIX!!+${PREFIX}+g < ${PKGDIR}/MESSAGE > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
