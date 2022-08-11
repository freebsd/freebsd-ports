PORTNAME=	rpm
PORTVERSION=	4.17.0
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	http://ftp.rpm.org/releases/rpm-4.17.x/
PKGNAMESUFFIX=	4

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Red Hat Package Manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libpopt.so:devel/popt \
		libnss3.so:security/nss \
		libzstd.so:archivers/zstd \
		libgcrypt.so:security/libgcrypt
RUN_DEPENDS=	bash:shells/bash \
		gxargs:misc/findutils

USES=		alias bdb sqlite cpe gmake iconv libarchive libtool \
		lua:53+ pathfix pkgconfig shebangfix tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed
SHEBANG_FILES=	scripts/check-prereqs \
		scripts/check-rpaths-worker scripts/pkgconfigdeps.sh \
		scripts/fontconfig.prov scripts/perl.prov scripts/perl.req  \
		scripts/find-lang.sh scripts/ocamldeps.sh
CONFIGURE_ARGS=	--enable-sqlite=yes\
		--with-popt-prefix="${LOCALBASE}" \
		--sysconfdir=${PREFIX}/etc \
		--localstatedir=/var \
		--without-javaglue \
		am_cv_python_version=${PYTHON_VER}${PYTHON_ABIVER} \
		ac_cv_lib_elf_gelf_getvernaux=no  # otherwise fails to build in presence of devel/elfutils
CONFIGURE_ENV=	LUA_CFLAGS=-I${LUA_INCDIR} \
		LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER} -lm"
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/nspr -I${LOCALBASE}/include/nss/nss \
		-I${BDB_INCLUDE_DIR} -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/nss \
		-L${BDB_LIB_DIR} -L${LUA_LIBDIR}

CONFLICTS_INSTALL=	rpm2cpio # bin/rpm2cpio

PLIST_SUB=	VERSION=${PORTVERSION} \
		OPSYS=${OPSYS:tl}

PORTDOCS=	*

OPTIONS_DEFINE=	PYTHON PLUGINS NLS DOCS
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes

PYTHON_CONFIGURE_ENABLE=python
PYTHON_USES=		python

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
NLS_LIBS=		-lintl

PLUGINS_CONFIGURE_ENABLE=plugins
PLUGINS_LIB_DEPENDS=	libdbus-1.so:devel/dbus

post-patch:
	@${REINPLACE_CMD} -e 's:\.\./\.\./bin/::' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/ __GLIBC__.*/& || defined(__FreeBSD__)/' \
		${WRKSRC}/system.h
	@${REINPLACE_CMD} -e 's/\<xargs\>/gxargs/g' \
		${WRKSRC}/scripts/brp-strip-static-archive \
		${WRKSRC}/scripts/check-buildroot \
		${WRKSRC}/scripts/check-rpaths \
		${WRKSRC}/scripts/vpkg-provides.sh

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} librpm/html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
