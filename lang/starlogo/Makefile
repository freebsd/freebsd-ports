# New ports collection makefile for:    StarLogo
# Version required:	1.0
# Date created:		14th November 1999
# Whom:			Jose Marques
#
# $FreeBSD$
#

DISTNAME=	java-starlogo-beta-2
PKGNAME=	starlogo-1.0
CATEGORIES=	lang java
MASTER_SITES=	http://el.www.media.mit.edu/starlogo/download/

MAINTAINER=	noway@nohow.demon.co.uk

RUN_DEPENDS=	${LOCALBASE}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk \
		${LOCALBASE}/jdk${JDK_VERSION}/lib/i386/green_threads/libtya.so:${PORTSDIR}/java/tya

WRKSRC=		${WRKDIR}/starlogo-1.0b2
JDK_VERSION=	1.1.8
NO_BUILD=	yes

post-patch:
	@${CAT} ${WRKSRC}/starlogo-unix | ${SED} -e s,@@PREFIX@@,${PREFIX},g | ${SED} -e s,@@JDK_VERSION@@,${JDK_VERSION},g > ${WRKSRC}/starlogo

do-install:
	@${MKDIR} ${PREFIX}/share/java/starlogo
	@${MKDIR} ${PREFIX}/share/java/starlogo/projects
	@${MKDIR} ${PREFIX}/share/java/starlogo/sounds
	@${INSTALL_SCRIPT} ${WRKSRC}/starlogo ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/starlogo.jar  ${PREFIX}/share/java/starlogo
	@${INSTALL_DATA} ${WRKSRC}/README        ${PREFIX}/share/java/starlogo
	@${INSTALL_DATA} ${WRKSRC}/reference.txt ${PREFIX}/share/java/starlogo
	@${INSTALL_DATA} ${WRKSRC}/projects/*    ${PREFIX}/share/java/starlogo/projects
	@${INSTALL_DATA} ${WRKSRC}/sounds/*      ${PREFIX}/share/java/starlogo/sounds

.include <bsd.port.mk>
