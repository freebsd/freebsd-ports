# New ports collection makefile for:	tya
# Date created:		16 May 1999
# Whom:			jburkhol@home.com
#
# $FreeBSD$
#

PORTNAME=	tya
PORTVERSION=	1.7.3
CATEGORIES=	java
MASTER_SITES=	http://sax.sax.de/~adlibit/
DISTNAME=	tya17v3
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${JAVADIR}/bin/java:${PORTSDIR}/java/jdk11

WRKSRC=		${WRKDIR}/${DISTNAME:S/a1/a1./}

ONLY_FOR_ARCHS=	i386

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-jdk=${JAVADIR}

JAVADIR?=	${LOCALBASE}/jdk1.1.8
JAVALIBDIR=	${PREFIX}/lib/tya

post-configure:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/README

do-install:
	@${MKDIR} ${JAVALIBDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/libtya.so ${JAVALIBDIR}

post-install:
	@${MKDIR} ${PREFIX}/share/tya
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/tya
	@${ECHO_MSG} ""
	@${ECHO_MSG} "See ${PREFIX}/share/tya/README for usage instructions."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
