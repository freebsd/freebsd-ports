# New ports collection makefile for:	tya
# Version required:	1.5
# Date created:		16 May 1999
# Whom:			jake@checker.org
#
# $FreeBSD$
#

DISTNAME=	tya15
PKGNAME=	tya-1.5
CATEGORIES=	java
MASTER_SITES=	ftp://gonzalez.cyberus.ca/pub/Linux/java/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jake@checker.org

BUILD_DEPENDS=	${LOCALBASE}/${JAVADIR}/bin/java:${PORTSDIR}/java/jdk

WRKSRC=		${WRKDIR}/tya1.5

ONLY_FOR_ARCHS=	i386

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-jdk=${LOCALBASE}/${JAVADIR}

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
