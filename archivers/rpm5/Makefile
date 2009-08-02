# New ports collection makefile for:	rpm
# Date created:				6 May 2003
# Whom:					Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	rpm
PORTVERSION=	5.0.3
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	http://rpm5.org/files/rpm/rpm-5.0/

MAINTAINER=	afb@rpm5.org
COMMENT=	The RPM Package Manager

LIB_DEPENDS=	db-4.5:${PORTSDIR}/databases/db45 \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		popt.0:${PORTSDIR}/devel/popt \
		beecrypt.10:${PORTSDIR}/security/beecrypt \
		neon.28:${PORTSDIR}/www/neon28 \
		magic:${PORTSDIR}/sysutils/file \
		xar:${PORTSDIR}/archivers/xar \
		pcre.0:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	${LOCALBASE}/bin/gsed:${PORTSDIR}/textproc/gsed
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen \
		${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz
.endif

DB_VERSION?=	45
USE_AUTOTOOLS=	libtool:22
LIBTOOLFILES=	configure db3/configure db/dist/configure \
		file/configure zlib/configure xar/configure
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
USE_PERL5_BUILD=5.8.0+
LATEST_LINK=	rpm5
CONFLICTS=	rpm-3.* rpm-4.*

.if !defined(WITHOUT_LUA)
CONFIGURE_ARGS+=--with-lua=external
USE_LUA=	5.1-
CPPFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}
.else
CONFIGURE_ARGS+=--without-lua
.endif

.if defined(WITH_PERL)
CONFIGURE_ARGS+=--with-perl
USE_PERL5=	yes
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=--without-perl
PLIST_SUB+=	PERL="@comment "
.endif

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=--with-python
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
CPPFLAGS+=	-I${PYTHON_INCLUDEDIR}
LDFLAGS+=	-L${PYTHON_LIBDIR}
.else
CONFIGURE_ARGS+=--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.endif

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=--with-apidocs
.endif

CPPFLAGS+=	-I${LOCALBASE}/include/db${DB_VERSION} -I${LOCALBASE}/include -I${LOCALBASE}/include/xar
LDFLAGS+=	-L${LOCALBASE}/lib/db${DB_VERSION} -L${LOCALBASE}/lib

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--with-db=external --with-bugreport="${MAINTAINER}" \
		--with-sqlite=external --with-dbabi=db \
		--with-zlib=external \
		--with-file=external \
		--with-xar=external \
		--with-pcre=external \
		--program-prefix="" \
		--sysconfdir=${PREFIX}/etc \
		--with-path-cfg=${PREFIX}/etc/rpm \
		--without-javaglue

MAN1=	gendiff.1
MAN8=	rpm.8 rpm2cpio.8 rpmbuild.8 rpmconstant.8 \
	rpmcache.8 rpmdeps.8 rpmgraph.8
.if defined(WITH_PERL)
MAN3=	RPM.3 RPM::Constant.3 RPM::Dependencies.3 \
	RPM::Files.3 RPM::Header.3 RPM::PackageIterator.3 \
	RPM::Problems.3 RPM::Spec.3 RPM::Transaction.3
MAN3PREFIX?=	${PREFIX}/lib/perl5/${PERL_VERSION}
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch::
	@${REINPLACE_CMD} -E -e \
		's:\$$\(libdir\)/pkgconfig:${PREFIX}/libdata/pkgconfig:' \
		${WRKSRC}/scripts/Makefile.in

.if defined(WITH_PERL)
post-configure:
	@cd ${CONFIGURE_WRKSRC}/perl && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile
.endif

post-build:
.if !defined(NOPORTDOCS)
	${MAKE} -C ${WRKSRC} apidocs
.endif
	${REINPLACE_CMD} -e "s:%{_rpmhome}/magic:${LOCALBASE}/share/file/magic:" \
		${WRKSRC}/macros

post-install:
.if !defined(NOPORTDOCS)
	# Install documentation
	${MKDIR} ${DOCSDIR}/apidocs/html
	cd ${WRKSRC}/apidocs/html && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} \
			${DOCSDIR}/apidocs/html/
.endif
	# Run package installation script
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
# DO NOT DELETE
