# New ports collection makefile for:	SETISupport
# Date Created:		1 Jul 2000
# Whom:			HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	SETISupport
PORTVERSION=	0.75
CATEGORIES=	astro java
MASTER_SITES=	http://otsubo.info/contents/SETISupport/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	gibbon@cocoa.freemail.ne.jp
COMMENT=	JAVA application that shows current state of seti@home client

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jre \
		${LOCALBASE}/sbin/setiathome:${PORTSDIR}/astro/setiathome

USE_XLIB=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/java/SETISupport
	@${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${PREFIX}/share/java/SETISupport
	@${INSTALL_SCRIPT} ${FILESDIR}/SETISupport.sh ${PREFIX}/bin/SETISupport
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
