# New ports collection makefile for:	openjit
# Date created:				26 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openjit
PORTVERSION=	1.1.15
CATEGORIES=	java
MASTER_SITES=	http://www.openjit.org/dist/
DISTNAME=	OpenJIT-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	${JAVADIR}/bin/java:${PORTSDIR}/java/jdk11

ONLY_FOR_ARCHS=	i386

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-jdk=${JAVADIR}

ALL_TARGET=	OpenJIT.jar

JAVADIR=	${LOCALBASE}/jdk1.1.8
JAVALIBDIR=	${PREFIX}/lib/OpenJIT
DOCDIR=		${PREFIX}/share/OpenJIT

post-configure:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/INSTALL

do-install:
	@${MKDIR} ${JAVALIBDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/libOpenJIT.so ${JAVALIBDIR}
	@${INSTALL_DATA} ${WRKSRC}/OpenJIT.jar ${JAVALIBDIR}

post-install:
	@${MKDIR} ${DOCDIR}
	@${INSTALL_MAN} ${WRKSRC}/INSTALL ${DOCDIR}/README
	@${ECHO_MSG} ""
	@${ECHO_MSG} "See ${DOCDIR}/README for usage instructions."
	@${ECHO_MSG} ""

.include <bsd.port.mk>
