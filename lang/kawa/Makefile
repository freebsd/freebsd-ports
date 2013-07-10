# Created by: Zach Garner <zach@neurosoft.org>
# $FreeBSD$

PORTNAME=	kawa
PORTVERSION=	1.13
CATEGORIES=	lang scheme java
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	kawa

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Java-based Scheme implementation

LICENSE=	MIT

USES=		gmake
USE_JAVA=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS=	--enable-kawa-frontend \
		--with-java-source=${JAVA_PORT_VERSION} \
		--with-libtool

MAN1=		kawa.1 qexo.1
INFO=		kawa

PLIST_FILES=	bin/kawa bin/qexo share/java/kawa.jar \
		share/java/kawa-${PORTVERSION}.jar

pre-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} \
		-e '/^JAR =/s|[a-zA-Z]*$$|${JAR}|g;'
	@${REINPLACE_CMD} -e 's|{JAVAC-javac}|{JAVAC-${JAVAC}}|g;' \
		-e 's|{JAVA-java}|{JAVA-${JAVA}}|g;' ${WRKSRC}/configure

regression-test: build
	cd ${WRKSRC} && ${GMAKE} check

.include <bsd.port.mk>
