# New ports collection makefile for:	JDK documentation
# Version required:	1.1.7
# Date created:		Mon Mar  8 10:10:42 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $Id: Makefile,v 1.2 1999/03/22 02:21:27 steve Exp $
#

DISTNAME=	jdk117B-doc
PKGNAME=	jdk-doc-1.1.7
CATEGORIES=	lang

MAINTAINER=	martti.kuparinen@ericsson.com

RESTRICTED=	"This software is under license and export control."
IS_INTERACTIVE=	"Requires manual fetch"
WRKSRC=		${WRKDIR}/jdk1.1.7B
NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-fetch:
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
	@echo ''
	@echo 'You have to fetch the documentation from'
	@echo '    http://java.sun.com/products/jdk/1.1/docs.html'
	@echo ''
	@echo 'Put ${DISTNAME}${EXTRACT_SUFX} in in ${DISTDIR}/ and run make again.'
	@echo ''
	@echo 'All this hassle is because of the license and export restrictions'
	@echo 'as described in'
	@echo '    http://java.sun.com/feedback/faq/downloading.html'
	@echo ''
	@exit 1
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk1.1.7
	(cd ${WRKSRC} && ${TAR} -cf - docs) \
		| (cd ${PREFIX}/jdk1.1.7 && ${TAR} -xf -)

post-install:
	@${SED} s+!!PREFIX!!+${PREFIX}+g < ${PKGDIR}/MESSAGE.tmpl > ${PKGDIR}/MESSAGE
	@${CAT} ${PKGDIR}/MESSAGE

pre-clean:
	@${RM} -f ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
