# Created by: Tilman Keskinoz <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cacao
PORTVERSION=	1.6.1
CATEGORIES=	java devel
MASTER_SITES=	http://www.complang.tuwien.ac.at/cacaojvm/download/cacao-${PORTVERSION}/

MAINTAINER=	java@FreeBSD.org
COMMENT=	JIT compiler for JAVA

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/share/classpath/glibj.zip:java/classpath
RUN_DEPENDS=	${LOCALBASE}/share/classpath/glibj.zip:java/classpath

USES=		gmake tar:xz
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-test-dependency-checks \
		--with-java-runtime-library=gnuclasspath \
		--with-java-runtime-library-prefix=${PREFIX} \
		--with-build-java-runtime-library-classes=${LOCALBASE}/share/classpath/glibj.zip
CONFIGURE_ENV=	JAVAC="${JAVAC}" JAR="${JAR}"

ONLY_FOR_ARCHS=	amd64 i386

OPTIONS_DEFINE=	JDK
OPTIONS_DEFAULT=JDK
JDK_DESC=	Build with native JDK

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJDK}
BUILD_DEPENDS+=	${LOCALBASE}/bootstrap-openjdk/bin/javac:java/bootstrap-openjdk
JAR=		${LOCALBASE}/bootstrap-openjdk/bin/jar
JAVAC=		${LOCALBASE}/bootstrap-openjdk/bin/javac
.else
.if defined(WITH_GCC)
GCC_SUFX=	${WITH_GCC:S/.//}
.endif
GCC_SUFX?=	46
BUILD_DEPENDS+=	gcj${GCC_SUFX}:lang/gcc${GCC_SUFX}
EXTRA_PATCHES=	${FILESDIR}/gcj.patch
JAR=		${LOCALBASE}/bin/gjar${GCC_SUFX}
JAVAC=		${LOCALBASE}/bin/gcj${GCC_SUFX}
JAVACFLAGS=	-C
CONFIGURE_ENV+=	JAVACFLAGS="${JAVACFLAGS}"
MAKE_ENV+=	JAVACFLAGS="${JAVACFLAGS}"
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/cacao/cacao \
	    ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/src/cacao/.libs/libjvm.so \
	    ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/classes/vm.zip \
	    ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/man/cacao.1 \
	    ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
