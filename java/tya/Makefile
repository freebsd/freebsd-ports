# New ports collection makefile for:	tya
# Version required:	1.3v2
# Date created:		16 May 1999
# Whom:			jake@checker.org
#
# $Id: Makefile,v 1.1.1.1 1999/06/09 00:59:02 steve Exp $
#

DISTNAME=	tya13v2
PKGNAME=	tya-1.3v2
CATEGORIES=	lang
MASTER_SITES=	ftp://gonzalez.cyberus.ca/pub/Linux/java/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jake@checker.org

BUILD_DEPENDS=	${PREFIX}/jdk1.1.8/bin/java:${PORTSDIR}/lang/jdk:install

WRKSRC=		${WRKDIR}/tya1.3v2

ONLY_FOR_ARCHS=	i386

HAS_CONFIGURE=	yes

JAVADIR=	jdk1.1.8
JAVALIBDIR=	${PREFIX}/${JAVADIR}/lib/i386/green_threads/

PLIST_SUB=	JAVADIR=${JAVADIR}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/libtya.so ${JAVALIBDIR}

post-install:
	@${MKDIR} ${PREFIX}/${JAVADIR}/tya
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/${JAVADIR}/tya
	@${ECHO_MSG} ""
	@${ECHO_MSG} "See ${PREFIX}/${JAVADIR}/tya/README for usage instructions."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
