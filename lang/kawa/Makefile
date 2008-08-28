# New ports collection makefile for:	Kawa
# Date created:				23 January 2002
# Whom:					Zach Garner <zach@neurosoft.org>
#
# $FreeBSD$
#

PORTNAME=		kawa
PORTVERSION=		1.9.1
CATEGORIES=		lang scheme java
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	kawa

MAINTAINER=		gahr@FreeBSD.org
COMMENT=		Java-based Scheme implementation

USE_JAVA=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-kawa-frontend \
			--with-java-source=${JAVA_PORT_VERSION} \

MAN1=			kawa.1 qexo.1
INFO=			kawa kawa-tour

.include <bsd.port.pre.mk>

pre-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-e 's|JAR = jar|JAR = ${JAR}|g;'
	@${REINPLACE_CMD} -e 's|{JAVAC-javac}|{JAVAC-${JAVAC}}|g;' \
		-e 's|{JAVA-java}|{JAVA-${JAVA}}|g; 4055d;' ${WRKSRC}/configure

.include <bsd.port.post.mk>
