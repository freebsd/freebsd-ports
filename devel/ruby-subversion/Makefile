PKGNAMEPREFIX=	ruby-

MAINTAINER=	michaelo@apache.org
COMMENT=	Ruby bindings for version control system
WWW=		https://subversion.apache.org/

USES+=		compiler:c11 ruby

PORTREVISION_LATEST=	0
PORTREVISION_LTS=		0

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

.include <bsd.port.post.mk>
