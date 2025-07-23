PORTNAME=	rpm
PORTVERSION=	4.18.2
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	http://ftp.rpm.org/releases/rpm-${PORTVERSION:R}.x/
PKGNAMESUFFIX=	4

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Red Hat Package Manager
WWW=		https://rpm.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libelf.so:devel/elfutils \
		gsed:textproc/gsed
LIB_DEPENDS=	libelf.so:devel/elfutils \
		libgcrypt.so:security/libgcrypt \
		libnss3.so:security/nss \
		libpopt.so:devel/popt \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	${LOCALBASE}/lib/libelf.so:devel/elfutils \
		bash:shells/bash \
		gxargs:misc/findutils

FLAVORS=		default noopenmp
FLAVOR?=		${FLAVORS:[1]}
noopenmp_PKGNAMESUFFIX=	4-noopenmp

USES=		alias cpe gmake iconv libarchive libtool lua pkgconfig \
		readline shebangfix sqlite tar:bzip2
USE_LDCONFIG=	yes

SHEBANG_FILES=			scripts/brp-compress scripts/check-prereqs \
				scripts/check-rpaths-worker \
				scripts/find-lang.sh scripts/fontconfig.prov \
				scripts/ocamldeps.sh scripts/perl.prov \
				scripts/perl.req scripts/pkgconfigdeps.sh \
				scripts/rpm_macros_provides.sh
GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=			--enable-bdb-ro \
				--enable-sqlite=yes \
				--localstatedir=/var \
				--sysconfdir=${PREFIX}/etc \
				--with-popt-prefix="${LOCALBASE}" \
				--without-javaglue \
				am_cv_python_version=${PYTHON_VER}${PYTHON_ABIVER}
.if ${FLAVOR} == noopenmp
CONFIGURE_ARGS+=		--disable-openmp
.endif
CONFIGURE_ENV=			LUA_CFLAGS=-I${LUA_INCDIR} \
				LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER} -lm"
INSTALL_TARGET=			install-strip

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/nspr \
		-I${LOCALBASE}/include/nss/nss -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/nss -L${LUA_LIBDIR}

CONFLICTS_INSTALL=	rpm2cpio rpm4 rpm4-noopenmp

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed

PLIST_SUB=	OPSYS=${OPSYS:tl} \
		VERSION=${PORTVERSION}

OPTIONS_DEFINE=		NLS PLUGINS PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_LIBS=		-lintl

PLUGINS_LIB_DEPENDS=		libdbus-1.so:devel/dbus
PLUGINS_CONFIGURE_ENABLE=	plugins
PYTHON_USES=			python
PYTHON_CONFIGURE_ENABLE=	python

post-patch:
	@${REINPLACE_CMD} -e 's/\<xargs\>/gxargs/g' \
		${WRKSRC}/scripts/brp-strip-static-archive \
		${WRKSRC}/scripts/check-buildroot \
		${WRKSRC}/scripts/check-rpaths \
		${WRKSRC}/scripts/vpkg-provides.sh

.include <bsd.port.mk>
