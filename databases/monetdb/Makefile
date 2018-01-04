# Created by: Jim Ohlstein <jim@ohlste.in>
# $FreeBSD$

PORTNAME=	monetdb
PORTVERSION=	11.15.19
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.monetdb.org/downloads/sources/Feb2013-SP6/
DISTNAME=	MonetDB-${PORTVERSION}

MAINTAINER=	jim@ohlste.in
COMMENT=	Multithreaded "column-oriented" SQL databasee

LICENSE=	MonetDB_License
LICENSE_NAME=	MonetDB Public License Version 1.1
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpcre.so:devel/pcre

USE_GNOME=	libxml2

USES=		bison iconv gmake libtool pkgconfig tar:xz
USE_LDCONFIG=	yes

USE_RC_SUBR=	monetdbd

WRKSRC=		${WRKDIR}/MonetDB-${PORTVERSION}

CONFIGURE_ENV=	openssl_CFLAGS=-I/usr/include \
		openssl_LIBS="-L/usr/lib -lssl -lcrypto"

LDFLAGS+=	-L${PREFIX}/lib
CFLAGS+=	-I${PREFIX}/include
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		CONSOLE CURL DATACELL FITS GEOM JDBC MEROCONTROL ODBC \
			PERL RDF RUBYGEMS SPHINXCLIENT TESTING OPTIMIZE
OPTIONS_RADIO=		PYTHON
OPTIONS_RADIO_PYTHON=	PYTHON2 PYTHON3
OPTIONS_SINGLE=		PASSWD_HASH_ALGORITHM
OPTIONS_SINGLE_PASSWD_HASH_ALGORITHM=	MD5 SHA1 RIPEMD160 SHA224 SHA256 \
			SHA384 SHA512
OPTIONS_DEFAULT=	PERL PYTHON2 SHA512
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=		yes

CONSOLE_DESC=	Direct console on the server (involves security risks)
CURL_DESC=	cURL support
DATACELL_DESC=	Datacell stream components (experimental)
FITS_DESC=	Support for FITS via CFITSIO
GEOM_DESC=	Support for geom module
JDBC_DESC=	Build the MonetDB JDBC (java) driver
MEROCONTROL_DESC=	Bbuild the Merovingian control driver (requires java)
ODBC_DESC=	ODBC support via unixODBC
PASSWD_HASH_ALGORITHM_DESC=	Password hash algorithm
MD5_DESC=	MD5 password hash
SHA1_DESC=	SHA1 password hash
RIPEMD160_DESC=	RIPEMD160 password hash
SHA224_DESC=	SHA224 password hash
SHA256_DESC=	SHA256 password hash
SHA384_DESC=	SHA384 password hash
SHA512_DESC=	SHA512 password hash
PERL_DESC=	Build and install Perl modules
PYTHON2_DESC=	Build and install Python 2.7 packages
PYTHON3_DESC=	Build and install Python 3.3 packages
RDF_DESC=	Support for RDF (experimental)
RUBYGEMS_DESC=	Build and install ruby gems
SPHINXCLIENT_DESC=	Sphinxclient support
TESTING_DESC=	Build and install testing (requires Python2 and Perl)
OPTIMIZE_DESC=	Extra compiler optimization flags

MONETDB_VARDIR?=	/var
MONETDB_LOGDIR?=	${MONETDB_VARDIR}/log/${PORTNAME}
MONETDB_RUNDIR?=	${MONETDB_VARDIR}/run/${PORTNAME}
MONETDB_LIBDIR?=	${PREFIX}/lib
MONETDB_INCLUDEDIR?=	${PREFIX}/include

PLIST_SUB+=	MONETDB_LOGDIR=${MONETDB_LOGDIR} \
		MONETDB_RUNDIR=${MONETDB_RUNDIR} \
		PERL_PORT=${PERL_PORT}

GNU_CONFIGURE=	yes

USERS=		monetdb
GROUPS=		monetdb

CONFIGURE_ARGS+=	--enable-gdk \
			--enable-monetdb5 \
			--enable-gdk \
			--enable-sql \
			--enable-jaql \
			--enable-largefile \
			--with-bz2 \
			--with-logdir=${MONETDB_LOGDIR} \
			--with-rundir=${MONETDB_RUNDIR} \
			--bindir=${PREFIX}/bin \
			--libdir=${MONETDB_LIBDIR} \
			--includedir=${MONETDB_INCLUDEDIR} \
			--localstatedir="${PREFIX}/var" \
			--docdir=${PREFIX}/${DATADIR}

SPHINXCLIENT_CONFIGURE_WITH=	sphinxclient
MEROCONTROL_CONFIGURE_ENABLE=	merocontrol
DATACELL_CONFIGURE_ENABLE=	datacell
OPTIMIZE_CONFIGURE_ENABLE=	optimize
RUBYGEMS_CONFIGURE_WITH=	rubygem
CONSOLE_CONFIGURE_ENABLE=	console
TESTING_CONFIGURE_ENABLE=	testing
FITS_CONFIGURE_ENABLE=		fits
GEOM_CONFIGURE_ENABLE=		geom
JDBC_CONFIGURE_ENABLE=		jdbc
ODBC_CONFIGURE_ENABLE=		odbc
PERL_CONFIGURE_WITH=		perl
RDF_CONFIGURE_ENABLE=		rdf

SPHINXCLIENT_LIB_DEPENDS=	libsphinxclient.so:textproc/libsphinxclient
RUBYGEMS_BUILD_DEPENDS=		gem:devel/ruby-gems
RUBYGEMS_RUN_DEPENDS=		gem:devel/ruby-gems
PYTHON3_BUILD_DEPENDS=		python3:lang/python3
PYTHON3_RUN_DEPENDS=		python3:lang/python3
CURL_LIB_DEPENDS=		libcurl.so:ftp/curl
FITS_LIB_DEPENDS=		libcfitsio.so:astro/cfitsio
GEOM_LIB_DEPENDS=		libgeos.so:graphics/geos
ODBC_LIB_DEPENDS=		libodbcinst.so:databases/unixODBC
PERL_BUILD_DEPENDS=		p5-DBI>=1.08:databases/p5-DBI
PERL_RUN_DEPENDS=		p5-DBI>=1.08:databases/p5-DBI
RDF_LIB_DEPENDS=		libraptor.so:textproc/raptor
PERL_USES=			perl5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFITS}
CATEGORIES+=	science
.endif

.if ${PORT_OPTIONS:MGEOM}
CATEGORIES+=	math
.endif

.if ${PORT_OPTIONS:MJDBC} || ${PORT_OPTIONS:MMEROCONTROL}
CATEGORIES+=	java
BUILD_DEPENDS+=	ant:devel/apache-ant
USE_JAVA=	yes
JAVA_VENDOR=	openjdk
JAVA_BUILD=	yes
JAVA_RUN=	yes
PLIST_SUB+=	JAVA=""
.else
PLIST_SUB+=	JAVA="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=	run build
CATEGORIES+=	perl5
.endif

.if ${PORT_OPTIONS:MRDF}
CATEGORIES+=	textproc
.endif

.if ${PORT_OPTIONS:MRUBYGEMS}
CATEGORIES+=	ruby
.endif

.if ${PORT_OPTIONS:MTESTING}
.  if empty(PORT_OPTIONS:MPYTHON2) || empty(PORT_OPTIONS:MPERL)
IGNORE=	testing option requires both Python2 and Perl
.  endif
.endif

.if ${PORT_OPTIONS:MPYTHON2} || ${PORT_OPTIONS:MPYTHON3}
CATEGORIES+=	python
PLIST_SUB+=	PYTHON=
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON2}
USES+=		python:2.7
PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}
CONFIGURE_ARGS+=	--with-python2=${PYTHON_CMD} \
			--without-python3
.else
CONFIGURE_ARGS+=	--without-python2
.endif

.if ${PORT_OPTIONS:MPYTHON3}
USES+=		python:3.4+
USE_PYTHON=	py3kplist
PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}
CONFIGURE_ARGS+=	--with-python3=${PYTHON_CMD} \
			--without-python2
.else
CONFIGURE_ARGS+=	--without-python3
.endif

.if ${PORT_OPTIONS:MMD5}
CONFIGURE_ARGS+=	--with-password-backend=MD5
.elif ${PORT_OPTIONS:MSHA1}
CONFIGURE_ARGS+=	--with-password-backend=SHA1
.elif ${PORT_OPTIONS:MRIPEMD160}
CONFIGURE_ARGS+=	--with-password-backend=RIPEMD160
.elif ${PORT_OPTIONS:MSHA224}
CONFIGURE_ARGS+=	--with-password-backend=SHA224
.elif ${PORT_OPTIONS:MSHA256}
CONFIGURE_ARGS+=	--with-password-backend=SHA256
.elif ${PORT_OPTIONS:MSHA384}
CONFIGURE_ARGS+=	-with-password-backend=SHA384
.elif ${PORT_OPTIONS:MSHA512}
CONFIGURE_ARGS+=	-with-password-backend=SHA512
.endif

pre-install:
	${INSTALL_DATA} ${WRKSRC}/clients/mapilib/monetdb-mapi.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/common/stream/monetdb-stream.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${MKDIR} ${STAGEDIR}${MONETDB_LOGDIR} \
		${STAGEDIR}${MONETDB_RUNDIR} \
		${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MPERL}
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/DBD/monetdb \
		${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/MonetDB
.endif
	${INSTALL_DATA} ${WRKSRC}/sql/dump-restore.* ${STAGEDIR}${DOCSDIR}

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/MonetDB-SQL-11.15.19
	${RM} -r ${STAGEDIR}${PREFIX}/etc/tmpfiles.d
	${MV} ${STAGEDIR}${PREFIX}/var/*  ${STAGEDIR}${PREFIX}
	${RMDIR} ${STAGEDIR}${PREFIX}/var
.if ${PORT_OPTIONS:MPERL}
	${MV} ${STAGEDIR}${PREFIX}/Mapi.pm \
		${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}
	${MV} ${STAGEDIR}${PREFIX}/DBD/monetdb.pm \
		${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/DBD
	${MV} ${STAGEDIR}${PREFIX}/DBD/monetdb/*.pm \
		${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/DBD/monetdb
	${MV} ${STAGEDIR}${PREFIX}/MonetDB \
		${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}
	${RM} -r ${STAGEDIR}${PREFIX}/DBD
.endif
.if ${PORT_OPTIONS:MPYTHON2} || ${PORT_OPTIONS:MPYTHON3}
	# Python support has broken DESTDIR support, force recompile
	cd ${STAGEDIR}${PREFIX} && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}
.endif

.include <bsd.port.mk>
