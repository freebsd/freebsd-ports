# New ports collection makefile for:	JDK documentation
# Version required:	1.1.8
# Date created:		Mon Mar  8 10:10:42 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $Id: Makefile,v 1.4 1999/05/06 00:13:56 taoka Exp $
#

DISTNAME=	jdk118-doc
PKGNAME=	jdk-doc-1.1.8
CATEGORIES=	lang

MAINTAINER=	martti.kuparinen@ericsson.com

RESTRICTED=	"This software is under license and export control."
IS_INTERACTIVE=	"Requires manual fetch"
VERSION=	1.1.8
WRKSRC=		${WRKDIR}/jdk${VERSION}
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/MESSAGE
PLIST_SUB+=	VERSION=${VERSION}

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
	${MKDIR} ${PREFIX}/jdk${VERSION}
	(cd ${WRKSRC} && ${TAR} -cf - docs) \
		| (cd ${PREFIX}/jdk${VERSION} && ${TAR} -xf -)
	@${SED} s+!!PREFIX!!+${PREFIX}+g < ${PKGDIR}/MESSAGE > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
