# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rpm
PORTVERSION=	4.14.2.1
CATEGORIES=	archivers
MASTER_SITES=	http://ftp.rpm.org/releases/rpm-4.14.x/
PKGNAMESUFFIX=	4

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Red Hat Package Manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt \
		libnss3.so:security/nss
RUN_DEPENDS=	bash:shells/bash

USES=		alias bdb gmake libarchive libtool lua:51 pathfix pkgconfig \
		shebangfix tar:bzip2
INVALID_BDB_VER=51
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
SHEBANG_FILES=	scripts/brp-python-bytecompile scripts/check-prereqs \
		scripts/check-rpaths-worker scripts/pythondeps.sh \
		scripts/mono-find-requires scripts/mono-find-provides \
		scripts/pkgconfigdeps.sh scripts/fontconfig.prov \
		scripts/rpmdb_loadcvt scripts/perl.prov scripts/perl.req  \
		scripts/pythondistdeps.py scripts/find-lang.sh \
		python/rpm/transaction.py
CONFIGURE_ARGS=	--with-external-db \
		--without-db \
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
	@${REINPLACE_CMD} -e 's/(hpux)/& || defined(__FreeBSD__)/' \
		${WRKSRC}/misc/fts.?
	@${REINPLACE_CMD} -e 's/ __GLIBC__.*/& || defined(__FreeBSD__)/' \
		${WRKSRC}/system.h

post-install-PYTHON-off:
	@${RM} ${STAGEDIR}${PREFIX}/lib/rpm/pythondistdeps.py

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} librpm/html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
