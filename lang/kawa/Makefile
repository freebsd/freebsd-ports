# Created by: Zach Garner <zach@neurosoft.org>
# $FreeBSD$

PORTNAME=	kawa
PORTVERSION=	2.1
CATEGORIES=	lang scheme java
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java-based Scheme implementation

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/makeinfo:print/texinfo

USES=		gmake readline
USE_JAVA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-kawa-frontend \
		--with-java-source=${JAVA_PORT_VERSION}
CONFIGURE_ENV=	MAKEINFO=${LOCALBASE}/bin/makeinfo
MAKE_ENV=	READLINE_LIB_PATH=${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=yes

INFO=		kawa

PLIST_FILES=	bin/kawa bin/qexo share/java/kawa.jar \
		share/java/kawa-${PORTVERSION}.jar \
		man/man1/kawa.1.gz man/man1/qexo.1.gz \

pre-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} \
		-e '/^JAR =/s|[a-zA-Z]*$$|${JAR}|g;'
	@${REINPLACE_CMD} -e 's|{JAVAC-javac}|{JAVAC-${JAVAC}}|g;' \
		-e 's|{JAVA-java}|{JAVA-${JAVA}}|g;' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^READLINE_LIB_PATH =/s|$$|-L${LOCALBASE}/lib|' \
		${WRKSRC}/bin/Makefile.in ${WRKSRC}/bin/Makefile.am

regression-test: build
	${MAKE_CMD} -C ${WRKSRC} check

.include <bsd.port.mk>
