# New ports collection makefile for:	JDK documentation
# Version required:	1.1.8
# Date created:		Mon Mar  8 10:10:42 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

DISTNAME=	jdk118-doc
PKGNAME=	jdk-doc-1.1.8
CATEGORIES=	java

MAINTAINER=	martti.kuparinen@ericsson.com

RESTRICTED=	"This software is under license and export control."
IS_INTERACTIVE=	"Requires manual fetch"
VERSION=	1.1.8
WRKSRC=		${WRKDIR}/jdk${VERSION}
NO_BUILD=	yes
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
	@${FALSE}
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk${VERSION}
	(cd ${WRKSRC} && ${TAR} -cf - docs) \
		| (cd ${PREFIX}/jdk${VERSION} && ${TAR} -xf -)
	@${CAT} ${PKGMESSAGE} | ${SED} s+!!PREFIX!!+${PREFIX}+g

.include <bsd.port.post.mk>
