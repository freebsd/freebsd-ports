PKGNAMEPREFIX=	ruby-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Ruby bindings for version control system
WWW=		https://subversion.apache.org/

USES+=		compiler:c11 ruby

PORTREVISION_114=	0
PORTREVISION_LTS=	0

SVN_BUILD_BINDINGS=	yes

.include "${.CURDIR}/../../devel/subversion/Makefile.addons"

CATEGORIES+=	ruby

CONFIGURE_ARGS+=	--without-gnome-keyring \
			--without-kwallet \
			--with-apxs=no

ALL_TARGET=	swig-rb-lib swig-rb
INSTALL_TARGET=	install-swig-rb

CFLAGS+=	-fdeclspec

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
