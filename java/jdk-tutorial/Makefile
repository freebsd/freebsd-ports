# New ports collection makefile for:	JDK tutorial
# Version required:	1.1.7
# Date created:		Tue Mar 23 10:18:20 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $Id: Makefile,v 1.2 1999/05/05 15:00:01 taoka Exp $
#

DISTNAME=	tutorial
PKGNAME=	jdk-tutorial-1.1.7
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.javasoft.com/docs/

MAINTAINER=	martti.kuparinen@ericsson.com

WRKSRC=		${WRKDIR}
RESTRICTED=	"This software is under license and export control."
NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/jdk1.1.7/docs/books/tutorial
	(cd ${WRKSRC} && ${TAR} -cf - * ) \
		| (cd ${PREFIX}/jdk1.1.7/docs/books/tutorial && ${TAR} -xf -)

post-install:
	@${SED} s+!!PREFIX!!+${PREFIX}+g < ${PKGDIR}/MESSAGE.tmpl > ${PKGDIR}/MESSAGE
	@${CAT} ${PKGDIR}/MESSAGE

pre-clean:
	@-${RM} -f ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
