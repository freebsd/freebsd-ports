# New ports collection makefile for:		gnu-regexp
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	gnu-regexp
PORTVERSION=	1.0.8
CATEGORIES=	java devel
MASTER_SITES=	ftp://ftp.cacas.org/pub/java/
DISTNAME=	gnu.regexp-${PORTVERSION}

MAINTAINER=	des@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/javac:${PORTSDIR}/java/jdk
RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/java:${PORTSDIR}/java/jdk

NO_BUILD=	yes

DOCDIR=		${PREFIX}/share/doc/${PORTNAME}

do-install:
	${MKDIR} ${DOCDIR}
	(cd ${WRKSRC}/docs && tar cf - . | tar --unlink -xpf - -C ${DOCDIR})
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-${PORTVERSION}.jar \
	    ${PREFIX}/share/java/classes/${PORTNAME}.jar

.include <bsd.port.mk>
