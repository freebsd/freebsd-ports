# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rpm
PORTVERSION=	5.2.1
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	http://rpm5.org/files/rpm/rpm-${PORTVERSION:R}/

MAINTAINER=	afb@rpm5.org
COMMENT=	The RPM Package Manager

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		popt.0:${PORTSDIR}/devel/popt \
		beecrypt.7:${PORTSDIR}/security/beecrypt \
		neon.27:${PORTSDIR}/www/neon29 \
		magic:${PORTSDIR}/sysutils/file \
		xar:${PORTSDIR}/archivers/xar \
		pcre.3:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed \
		${LOCALBASE}/lib/libuuid.a:${PORTSDIR}/misc/ossp-uuid \
		bash:${PORTSDIR}/shells/bash

SH=		${LOCALBASE}/bin/bash

OPTIONS_DEFINE=	PERL PYTHON LUA
OPTIONS_DEFAULT=	PYTHON LUA

DB_VERSION?=	47
USE_BDB=	${DB_VERSION}
USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	configure db3/configure db/dist/configure \
		file/configure xar/configure
CONFIGURE_ARGS=	--without-js
USES=		gmake perl5
USE_PERL5=	build
USE_LDCONFIG=	yes
LATEST_LINK=	rpm5
CONFLICTS=	rpm-3.* rpm-4.*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLUA}
CONFIGURE_ARGS+=--with-lua=external \
		--with-syck=external
USE_LUA=	5.1-
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsyck.a:${PORTSDIR}/textproc/syck
CPPFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}
.else
CONFIGURE_ARGS+=--without-lua \
		--without-syck
.endif

.if ${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+=--with-perl
CONFIGURE_ENV+=	__PERL=${PERL}
USE_PERL5=	yes
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=--without-perl
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=--with-python=${PYTHON_VER}
CONFIGURE_ENV+=	__PYTHON=${PYTHON_CMD}
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
CPPFLAGS+=	-I${PYTHON_INCLUDEDIR}
LDFLAGS+=	-L${PYTHON_LIBDIR}
.else
CONFIGURE_ARGS+=--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=--enable-nls
USES+=		gettext iconv
.else
CONFIGURE_ARGS+=--disable-nls
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		dot:${PORTSDIR}/graphics/graphviz \
		${LOCALBASE}/lib/X11/fonts/freefont-ttf/FreeSans.ttf:${PORTSDIR}/x11-fonts/freefont-ttf
CONFIGURE_ARGS+=--with-apidocs
.endif

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

MAN1=	gendiff.1 rpmgrep.1
MAN8=	rpm.8 rpm2cpio.8 rpmbuild.8 rpmconstant.8 \
	rpmcache.8 rpmdeps.8 rpmmtree.8
.if defined(WITH_PERL)
MAN3=	RPM.3 RPM::Constant.3 RPM::Dependencies.3 \
	RPM::Files.3 RPM::Header.3 RPM::PackageIterator.3 \
	RPM::Problems.3 RPM::Spec.3 RPM::Transaction.3
MAN3PREFIX?=	${PREFIX}/lib/perl5/${PERL_VER}
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	lzma:${PORTSDIR}/archivers/xz
.endif

.if ${OSVERSION} <= 701000
MANUAL_PACKAGE_BUILD=	hangs on pointyhat
.endif

post-patch::
	@${REINPLACE_CMD} -E -e \
		's:\$$\(libdir\)/pkgconfig:${PREFIX}/libdata/pkgconfig:' \
		${WRKSRC}/scripts/Makefile.am ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e "s:/bin/sh:/usr/bin/env bash:" \
		${WRKSRC}/scripts/gendiff

post-configure:
.if ${PORT_OPTIONS:MPERL}
	@cd ${CONFIGURE_WRKSRC}/perl && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile
.endif
	@echo "DOT_FONTPATH = ${LOCALBASE}/lib/X11/fonts/freefont-ttf" >> ${WRKSRC}/Doxyfile

.if ${PORT_OPTIONS:MDOCS}
post-build:
	${MAKE} -C ${WRKSRC} apidocs
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	# Install documentation
	${MKDIR} ${DOCSDIR}/apidocs/html
	cd ${WRKSRC}/apidocs/html && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} \
			${DOCSDIR}/apidocs/html/
.endif
	# Run package installation script
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
