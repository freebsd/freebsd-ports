# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rpm
PORTVERSION=	4.11.1
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://rpm.org/releases/rpm-${PORTVERSION:R}.x/ \
		ftp://ftp.mirrorservice.org/sites/ftp.rpm.org/pub/rpm/dist/rpm-${PORTVERSION:E}.x/
PKGNAMESUFFIX=	4

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The RPM Package Manager

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libnss3.so:${PORTSDIR}/security/nss
BUILD_DEPENDS=	${LOCALBASE}/bin/gsed:${PORTSDIR}/textproc/gsed

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON

USES=		gmake shebangfix
USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_LUA=	5.1+
USE_BDB=	46+
INVALID_BDB_VER=51
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFLICTS_INSTALL=	rpm-[35].* rpm5-*
SHEBANG_FILES=	scripts/brp-python-bytecompile scripts/check-prereqs \
		scripts/check-rpaths-worker scripts/pythondeps.sh \
		scripts/mono-find-requires scripts/mono-find-provides \
		scripts/pkgconfigdeps.sh scripts/fontconfig.prov \
		scripts/rpmdb_loadcvt \
		scripts/perl.prov scripts/perl.req scripts/perldeps.pl \
		scripts/osgideps.pl scripts/tcl.req

CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/nspr -I${LOCALBASE}/include/nss/nss \
		-I${BDB_INCLUDE_DIR} -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/nss \
		-L${BDB_LIB_DIR} -L${LUA_LIBDIR}
CONFIGURE_ARGS+=--with-external-db \
		--without-db \
		--with-popt-prefix="${LOCALBASE}" \
		--sysconfdir=${PREFIX}/etc \
		--localstatedir=/var \
		--without-javaglue \
		LUA_CFLAGS=-I${LUA_INCDIR} \
		LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER} -lm"
PLIST_SUB+=	VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=--enable-python
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
CPPFLAGS+=	-I${PYTHON_INCLUDEDIR}
LDFLAGS+=	-L${PYTHON_LIBDIR}
SHEBANG_FILES+=	python/rpm/transaction.py
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e '/^pkgconfigdir/s:/:data/:' \
		-e 's:\.\./\.\./bin/::' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's/(hpux)/& || defined(__FreeBSD__)/' \
		${WRKSRC}/misc/fts.?
	${REINPLACE_CMD} -e 's/ __GLIBC__.*/& || defined(__FreeBSD__)/' \
		${WRKSRC}/system.h

post-install:
.if ${PORT_OPTIONS:MDOCS}
	# Install documentation
	${MKDIR} ${STAGEDIR}${DOCSDIR}/librpm/html
	cd ${WRKSRC}/doc/librpm/html && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} \
			${STAGEDIR}${DOCSDIR}/librpm/html/
.endif
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librpm*.so.* \
		${STAGEDIR}${PREFIX}/lib/rpm-plugins/*.so
.if ${PORT_OPTIONS:MPYTHON}
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/rpm/*.so
.endif

.include <bsd.port.post.mk>
