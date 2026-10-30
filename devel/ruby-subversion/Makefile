PKGNAMEPREFIX=	ruby-

MAINTAINER=	michaelo@apache.org
COMMENT=	Ruby bindings for Apache Subversion
WWW=		https://subversion.apache.org/

USES+=		compiler:c11 ruby

PORTREVISION_LATEST=	1
PORTREVISION_LTS=		1

SVN_BUILD_BINDINGS=	yes

.include "${.CURDIR}/../../devel/subversion/Makefile.addons"

CATEGORIES+=	ruby

CONFIGURE_ARGS+=	--with-swig-ruby=${RUBY} \
			--without-swig-perl \
			--without-swig-python \
			--without-gnome-keyring \
			--without-kwallet \
			--with-apxs=no

ALL_TARGET=	swig-rb-lib swig-rb
INSTALL_TARGET=	install-swig-rb

CFLAGS+=	-fdeclspec

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion -Wno-error=incompatible-function-pointer-types
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsvn_swig_ruby-1.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}/svn/ext/*.so
	${RM} ${STAGEDIR}${PREFIX}/lib/libsvn_swig_ruby-1.a

.include <bsd.port.post.mk>
