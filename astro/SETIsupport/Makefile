# New ports collection makefile for:	SETISupport
# Date Created:		1 Jul 2000
# Whom:			HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	SETISupport
PORTVERSION=	0.74
CATEGORIES=	astro java
MASTER_SITES=	http://members5.cool.ne.jp/%7Egrgr56/SETITest/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	hym@cocoa.freemail.ne.jp

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jre \
		${LOCALBASE}/sbin/setiathome:${PORTSDIR}/astro/setiathome

USE_XLIB=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/java/SETISupport
	@${INSTALL_DATA} ${DISTDIR}/SETISupport.jar ${PREFIX}/share/java/SETISupport
	@${INSTALL_SCRIPT} ${FILESDIR}/SETISupport.sh ${PREFIX}/bin/SETISupport
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
