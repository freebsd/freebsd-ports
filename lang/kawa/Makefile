# New ports collection makefile for:	Kawa
# Date created:				23 January 2002
# Whom:					Zach Garner <zach@neurosoft.org>
#
# $FreeBSD$
#

PORTNAME=		kawa
PORTVERSION=		1.7
CATEGORIES=		lang scheme java
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	kawa

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Java-based Scheme implementation

BUILD_DEPENDS=		gsed:${PORTSDIR}/textproc/gsed

NEED_JAVAC=		yes
USE_JAVA=		1.2+
USE_REINPLACE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-kawa-frontend --program-prefix=''

MAN1=			kawa.1
INFO=			kawa kawa-tour

pre-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-e 's|sed |gsed |g;' \
		-e 's|JAR = jar|JAR = ${JAR}|g;'
	@${REINPLACE_CMD} -e 's|{JAVAC-javac}|{JAVAC-${JAVAC}}|g;' \
		-e 's|{JAVA-java}|{JAVA-${JAVA}}|g;' ${WRKSRC}/configure

.include <bsd.port.mk>
