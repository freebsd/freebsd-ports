# Created by: Tilman Keskinoz <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cacao
PORTVERSION=	1.6.1
CATEGORIES=	java devel
MASTER_SITES=	http://www.complang.tuwien.ac.at/cacaojvm/download/cacao-${PORTVERSION}/

MAINTAINER=	java@FreeBSD.org
COMMENT=	JIT compiler for JAVA

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/share/classpath/glibj.zip:${PORTSDIR}/java/classpath
RUN_DEPENDS=	${LOCALBASE}/share/classpath/glibj.zip:${PORTSDIR}/java/classpath

USES=		gmake
GNU_CONFIGURE=	yes
USE_XZ=		yes

MAN1=		cacao.1

CONFIGURE_ARGS=	--disable-test-dependency-checks \
		--with-java-runtime-library=gnuclasspath \
		--with-java-runtime-library-prefix=${PREFIX} \
		--with-build-java-runtime-library-classes=${LOCALBASE}/share/classpath/glibj.zip
CONFIGURE_ENV=	JAVAC="${JAVAC}" JAR="${JAR}"

ONLY_FOR_ARCHS=	amd64 i386

OPTIONS_DEFINE=	JDK
OPTIONS_DEFAULT=JDK
JDK_DESC=	Build with native JDK

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJDK}
BUILD_DEPENDS+=	${LOCALBASE}/bootstrap-openjdk/bin/javac:${PORTSDIR}/java/bootstrap-openjdk
JAR=		${LOCALBASE}/bootstrap-openjdk/bin/jar
JAVAC=		${LOCALBASE}/bootstrap-openjdk/bin/javac
.else
.if defined(WITH_GCC)
GCC_SUFX=	${WITH_GCC:S/.//}
.endif
GCC_SUFX?=	46
BUILD_DEPENDS+=	gcj${GCC_SUFX}:${PORTSDIR}/lang/gcc${GCC_SUFX}
EXTRA_PATCHES=	${FILESDIR}/gcj.patch
JAR=		${LOCALBASE}/bin/gjar${GCC_SUFX}
JAVAC=		${LOCALBASE}/bin/gcj${GCC_SUFX}
JAVACFLAGS=	-C
CONFIGURE_ENV+=	JAVACFLAGS="${JAVACFLAGS}"
MAKE_ENV+=	JAVACFLAGS="${JAVACFLAGS}"
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' \
	    ${WRKSRC}/configure ${WRKSRC}/src/mm/boehm-gc/configure

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/cacao/cacao ${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/src/cacao/.libs/libjvm.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/classes/vm.zip ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/man/cacao.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
