# New ports collection makefile for:	kawa
# Date created:		23 January 2002
# Whom:			zach@neurosoft.org
#
# $FreeBSD$
#

PORTNAME=		kawa
PORTVERSION=		1.6.98
PORTREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	kawa

MAINTAINER=		zach@neurosoft.org

BUILD_DEPENDS= 	gsed:${PORTSDIR}/textproc/gsed

USE_JAVA=	1.2+
NEED_JAVAC=	YES

MAN1: kawa

CONFIGURE_ARGS=	--enable-kawa-frontend
GNU_CONFIGURE=	yes

pre-patch:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi \
		 -e 's|sed |gsed |g;' \
		 -e 's|JAR = jar|JAR = ${JAR}|g;'
	perl -pi -e 's|{JAVAC-javac}|{JAVAC-${JAVAC}}|g;' \
		 -e 's|{JAVA-java}|{JAVA-${JAVA}}|g;' ${WRKSRC}/configure

.include <bsd.port.mk>
