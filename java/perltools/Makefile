# New ports collection makefile for:    PerlTools
# Date created:		2000/08/12
# Whom:			Marcin Cieslak
#
# $FreeBSD$
#

PORTNAME=	PerlTools
PORTVERSION=	1.2
CATEGORIES=	java
MASTER_SITES=	http://www.savarese.org/oro/downloads/download/

MAINTAINER=	saper@system.pl

RUN_DEPENDS=	${LOCALBASE}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.0a
JDK_VERSION=	1.1.8
NO_BUILD=	yes
NO_CDROM=	"See the license"

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC}; \
		${MKDIR} ${PREFIX}/share/java/classes/; \
		${CP} ${WRKSRC}/PerlTools.jar ${PREFIX}/share/java/classes/; \
		${MKDIR} ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} CHANGES License.html README ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} -R doc ${PREFIX}/share/java/${PKGNAME}/; \
		${CP} -R examples ${PREFIX}/share/java/${PKGNAME}/

.include <bsd.port.post.mk>
