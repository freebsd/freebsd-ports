PKGNAMEPREFIX=	java-

MAINTAINER=	michaelo@apache.org
COMMENT=	Java bindings for Apache Subversion
WWW=		https://subversion.apache.org/

USES=		compiler java
JAVA_OS=	native

PORTREVISION_LATEST=	4
PORTREVISION_LTS=		4

SVN_BUILD_BINDINGS=	yes

.include "${.CURDIR}/../../devel/subversion/Makefile.addons"

CATEGORIES+=	java

CONFIGURE_ARGS+=	--enable-javahl \
			--without-swig-perl \
			--without-siwg-python \
			--without-swig-ruby \
			--with-jdk=${JAVA_HOME} \
			--with-jikes=no \
			--without-gnome-keyring \
			--without-kwallet \
			--with-apxs=no

MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	javahl
INSTALL_TARGET=	install-javahl

post-configure:
.if ${COMPILER_TYPE} == clang
	${REINPLACE_CMD} "s#^LT_CXX_LIBADD = .*#LT_CXX_LIBADD =#" ${WRKSRC}/Makefile
.else
	${DO_NADA}
.endif

pre-build:
	@${MKDIR} ${WRKSRC}/subversion/bindings/java/javahl/classes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsvnjavahl-1.so.0.0.0
	${RM} ${STAGEDIR}${PREFIX}/lib/libsvnjavahl-1.a

.include <bsd.port.post.mk>
