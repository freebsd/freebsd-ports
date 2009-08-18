# New ports collection makefile for:	Kawa
# Date created:				23 January 2002
# Whom:					Zach Garner <zach@neurosoft.org>
#
# $FreeBSD$
#

PORTNAME=	kawa
PORTVERSION=	1.9.90
CATEGORIES=	lang scheme java
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	kawa

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Java-based Scheme implementation

USE_JAVA=	yes
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-kawa-frontend \
		--with-java-source=${JAVA_PORT_VERSION} \
		--with-libtool

MAN1=		kawa.1 qexo.1
INFO=		kawa

PLIST_FILES=	bin/kawa bin/qexo share/java/kawa.jar \
		share/java/kawa-${PORTVERSION}.jar

pre-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-e 's|JAR = jar|JAR = ${JAR}|g;'
	@${REINPLACE_CMD} -e 's|{JAVAC-javac}|{JAVAC-${JAVAC}}|g;' \
		-e 's|{JAVA-java}|{JAVA-${JAVA}}|g; 4912d;' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|--mode=install|--mode=install install|g' \
	    ${WRKSRC}/bin/Makefile.am ${WRKSRC}/bin/Makefile.in

.include <bsd.port.mk>
