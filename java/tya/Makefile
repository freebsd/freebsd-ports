# New ports collection makefile for:	tya
# Date created:		16 May 1999
# Whom:			jburkhol@home.com
#
# $FreeBSD$
#

PORTNAME=	tya
PORTVERSION=	1.7
CATEGORIES=	java
MASTER_SITES=	http://sax.sax.de/~adlibit/
DISTNAME=	tya17
EXTRACT_SUFX=	.tgz

MAINTAINER=	jburkhol@home.com

BUILD_DEPENDS=	${LOCALBASE}/${JAVADIR}/bin/java:${PORTSDIR}/java/jdk

WRKSRC=		${WRKDIR}/tya1.7

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
