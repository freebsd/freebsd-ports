PORTNAME=	rpm
PORTVERSION=	4.18.1
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	http://ftp.rpm.org/releases/rpm-${PORTVERSION:R}.x/
PKGNAMESUFFIX=	4

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Red Hat Package Manager
WWW=		https://rpm.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed \
		${LOCALBASE}/lib/libelf.so:devel/elfutils
LIB_DEPENDS=	libpopt.so:devel/popt \
		libnss3.so:security/nss \
		libzstd.so:archivers/zstd \
		libgcrypt.so:security/libgcrypt \
		libelf.so:devel/elfutils
RUN_DEPENDS=	bash:shells/bash \
		gxargs:misc/findutils \
		${LOCALBASE}/lib/libelf.so:devel/elfutils

USES=		alias bdb sqlite cpe gmake iconv libarchive libtool \
		lua pathfix pkgconfig shebangfix tar:bzip2
USE_LDCONFIG=	yes

SHEBANG_FILES=	scripts/check-prereqs \
		scripts/check-rpaths-worker scripts/pkgconfigdeps.sh \
		scripts/fontconfig.prov scripts/perl.prov scripts/perl.req \
		scripts/find-lang.sh scripts/ocamldeps.sh \
		scripts/rpm_macros_provides.sh
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sqlite=yes\
		--with-popt-prefix="${LOCALBASE}" \
		--sysconfdir=${PREFIX}/etc \
		--localstatedir=/var \
		--without-javaglue \
		am_cv_python_version=${PYTHON_VER}${PYTHON_ABIVER}
CONFIGURE_ENV=	LUA_CFLAGS=-I${LUA_INCDIR} \
		LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER} -lm"
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/nspr -I${LOCALBASE}/include/nss/nss \
		-I${BDB_INCLUDE_DIR} -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/nss \
		-L${BDB_LIB_DIR} -L${LUA_LIBDIR}

CONFLICTS_INSTALL=	rpm2cpio # bin/rpm2cpio

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed

PLIST_SUB=	VERSION=${PORTVERSION} \
		OPSYS=${OPSYS:tl}

OPTIONS_DEFINE=	PYTHON PLUGINS NLS
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_LIBS=		-lintl

PLUGINS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
PLUGINS_CONFIGURE_ENABLE=plugins
PYTHON_USES=		python
PYTHON_CONFIGURE_ENABLE=python

post-patch:
	@${REINPLACE_CMD} -e 's:\.\./\.\./bin/::' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/ __GLIBC__.*/& || defined(__FreeBSD__)/' \
		${WRKSRC}/system.h
	@${REINPLACE_CMD} -e 's/\<xargs\>/gxargs/g' \
		${WRKSRC}/scripts/brp-strip-static-archive \
		${WRKSRC}/scripts/check-buildroot \
		${WRKSRC}/scripts/check-rpaths \
		${WRKSRC}/scripts/vpkg-provides.sh

.include <bsd.port.mk>
