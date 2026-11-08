PKGNAMEPREFIX=	java-

MAINTAINER=	michaelo@apache.org
COMMENT=	Java bindings for Apache Subversion
WWW=		https://subversion.apache.org/

USES=		java:build

PORTREVISION_LATEST=	0
PORTREVISION_LTS=		9

.include "${.CURDIR}/../../devel/subversion/Makefile.addons"

CATEGORIES+=	java

BUILD_DEPENDS+=	${JAVAJARDIR}/junit.jar:java/junit

CONFIGURE_ARGS+=	--enable-javahl \
			--with-junit=${JAVAJARDIR}/junit.jar \
			--without-swig-perl \
			--without-swig-python \
			--without-swig-ruby \
			--with-jdk=${JAVA_HOME} \
			--with-jikes=no \
			--without-gnome-keyring \
			--without-kwallet \
			--with-apxs=no

# real race: build.conf's Java-target add-deps only threads into the
# phony aggregate target, not the javac -h compile rule itself, so -j
# can run javahl-types-java before javahl-java's NativeResources.class
# exists ("cannot find symbol: variable NativeResources")
MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	javahl
INSTALL_TARGET=	install-javahl

pre-configure:
	${REINPLACE_CMD} "s#^javahl_javadir = .*#javahl_javadir = ${JAVAJARDIR}#" ${WRKSRC}/Makefile.in

pre-build:
	@${MKDIR} ${WRKSRC}/subversion/bindings/java/javahl/classes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsvnjavahl-1.so.0.0.0
	${RM} ${STAGEDIR}${PREFIX}/lib/libsvnjavahl-1.a

.include <bsd.port.post.mk>
