# New ports collection makefile for:	kawa
# Date created:		23 January 2002
# Whom:			zach@neurosoft.org
#
# $FreeBSD$
#

PORTNAME=		kawa
PORTVERSION=		1.6.98
PORTREVISION=		2
CATEGORIES=		lang scheme
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	kawa

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Java-based Scheme implementation

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

USE_JAVA=	1.2+
USE_PERL5_BUILD=YES
NEED_JAVAC=	YES

MAN1=		kawa.1

CONFIGURE_ARGS=	--enable-kawa-frontend
GNU_CONFIGURE=	yes

pre-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi \
		 -e 's|sed |gsed |g;' \
		 -e 's|JAR = jar|JAR = ${JAR}|g;'
	${PERL} -pi -e 's|{JAVAC-javac}|{JAVAC-${JAVAC}}|g;' \
		 -e 's|{JAVA-java}|{JAVA-${JAVA}}|g;' ${WRKSRC}/configure

.include <bsd.port.mk>
