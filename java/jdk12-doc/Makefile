# New ports collection makefile for:	JDK documentation
# Date created:		Mon Mar  8 10:10:42 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	jdk-doc
PORTVERSION=	1.1.8
CATEGORIES=	java
DISTNAME=	jdk-1_1_8_003-doc

MAINTAINER=	martti.kuparinen@iki.fi

RESTRICTED=	"This software is under license and export control."
IS_INTERACTIVE=	"Requires manual fetch"
WRKSRC=		${WRKDIR}/jdk${PORTVERSION}
NO_BUILD=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

do-fetch:
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
	@${ECHO_MSG} ''
	@${ECHO_MSG} 'You have to fetch the documentation from'
	@${ECHO_MSG} '    http://java.sun.com/products/jdk/1.1/docs.html'
	@${ECHO_MSG} ''
	@${ECHO_MSG} 'Put ${DISTNAME}${EXTRACT_SUFX} in in ${DISTDIR}/ and run make again.'
	@${ECHO_MSG} ''
	@${ECHO_MSG} 'All this hassle is because of the license and export restrictions'
	@${ECHO_MSG} 'as described in'
	@${ECHO_MSG} '    http://java.sun.com/feedback/faq/downloading.html'
	@${ECHO_MSG} ''
	@${FALSE}
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk${PORTVERSION}
	${CP} -R ${WRKSRC}/docs ${PREFIX}/jdk${PORTVERSION}/
	@${SED} 's+\$${PREFIX}+${PREFIX}+g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
