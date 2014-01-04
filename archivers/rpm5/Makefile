# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rpm
PORTVERSION=	5.2.1
PORTREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	http://rpm5.org/files/rpm/rpm-${PORTVERSION:R}/
PKGNAMESUFFIX=	5

MAINTAINER=	afb@rpm5.org
COMMENT=	The RPM Package Manager

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libpopt.so:${PORTSDIR}/devel/popt \
		libbeecrypt.so:${PORTSDIR}/security/beecrypt \
		libneon.so:${PORTSDIR}/www/neon29 \
		libmagic.so:${PORTSDIR}/sysutils/file \
		libxar.so:${PORTSDIR}/archivers/xar \
		libpcre.so:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/lib/libuuid.a:${PORTSDIR}/misc/ossp-uuid \
		bash:${PORTSDIR}/shells/bash

SH=		${LOCALBASE}/bin/bash

OPTIONS_DEFINE=	PERL PYTHON LUA DOCS
OPTIONS_DEFAULT=	PYTHON LUA

DB_VERSION?=	47
USE_BDB=	${DB_VERSION}
USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	configure db3/configure db/dist/configure \
		file/configure xar/configure
CONFIGURE_ARGS=	--without-js
USES=		gmake perl5 shebangfix
SHEBANG_FILES=	scripts/*
USE_PERL5=	build
USE_LDCONFIG=	yes
CONFLICTS=	rpm-3.* rpm-4.* rpm4-*

OPTIONS_SUB=	yes

LUA_USE=	LUA=5.1-
LUA_BUILD_DEPENDS=	${LOCALBASE}/lib/libsyck.a:${PORTSDIR}/textproc/syck
LUA_CPPFLAGS=	-I${LUA_INCDIR}
LUA_LDFLAGS=	-L${LUA_LIBDIR}
LUA_CONFIGURE_ON=	--with-lua=external --with-syck=external
LUA_CONFIGURE_OFF=	--without-lua --without-syck

PERL_CONFIGURE_WITH=	perl
PERL_USE=	PERL5=run
PERL_CONFIGURE_ENV=	__PERL=${PERL}

PYTHON_USE=	PYTHON=yes
PYTHON_CONFIGURE_ON=	--with-python=${PYTHON_VER}
PYTHON_CONFIGURE_OFF=	--without-python
PYTHON_CONFIGURE_ENV=	__PYTHON=${PYTHON_CMD}
PYTHON_CPPFLAGS=	-I${PYTHON_INCLUDEDIR}
PYTHON_LDFLAGS=		-L${PYTHON_LIBDIR}

NLS_USES=	gettext iconv
NLS_CONFIGURE_ENABLE=	nls

DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen \
			dot:${PORTSDIR}/graphics/graphviz \
			${LOCALBASE}/lib/X11/fonts/freefont-ttf/FreeSans.ttf:${PORTSDIR}/x11-fonts/freefont-ttf
DOCS_CONFIGURE_WITH=	apidocs
PORTDOCS=	*

CPPFLAGS+=	-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include -I${LOCALBASE}/include/xar
LDFLAGS+=	-L${BDB_LIB_DIR} -L${LOCALBASE}/lib

CONFIGURE_ARGS+=--with-db=external --with-bugreport="${MAINTAINER}" \
		--with-sqlite=external --with-dbabi=db \
		--with-zlib=external \
		--with-file=external \
		--with-xar=external \
		--with-xz=external \
		--with-pcre=external \
		--with-uuid=external \
		--program-prefix="" \
		--sysconfdir=${PREFIX}/etc \
		--with-path-cfg=${PREFIX}/etc/rpm \
		--with-path-magic=${LOCALBASE}/share/file/magic

MAN3PREFIX?=	${PREFIX}/lib/perl5/${PERL_VER}

.include <bsd.port.options.mk>

post-patch::
	@${REINPLACE_CMD} -E -e \
		's:\$$\(libdir\)/pkgconfig:${PREFIX}/libdata/pkgconfig:' \
		${WRKSRC}/scripts/Makefile.am ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s:/bin/sh:/usr/bin/env bash:" \
		${WRKSRC}/scripts/gendiff

post-configure:
.if ${PORT_OPTIONS:MPERL}
	@${REINPLACE_CMD} -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' ${CONFIGURE_WRKSRC}/perl/Makefile
.endif
	@echo "DOT_FONTPATH = ${LOCALBASE}/lib/X11/fonts/freefont-ttf" >> ${WRKSRC}/Doxyfile

.if ${PORT_OPTIONS:MDOCS}
post-build:
	${MAKE} -C ${WRKSRC} apidocs
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	# Install documentation
	${MKDIR} ${STAGEDIR}${DOCSDIR}/apidocs/html
	cd ${WRKSRC}/apidocs/html && ${COPYTREE_SHARE} . ${DOCSDIR}/apidocs/html/
.endif

.include <bsd.port.mk>
