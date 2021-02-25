# Created by: Wes Peters <wes@softweyr.com>
# $FreeBSD$

PORTNAME=	snobol4
PORTVERSION=	2.2.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.snobol4.org/snobol/

MAINTAINER=	phil@snobol4.org
COMMENT=	Full SNOBOL4 language with SPITBOL, BLOCKS, and other extensions

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

# will also use libedit, but poundriere tests fail.
USES=		readline ssl

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAKE_JOBS_UNSAFE=yes
ALL_TARGET=	build_all
INSTALL_TARGET=	install_notiming

PLIST_SUB+=	VERSION=${PORTVERSION}

# openssl in base system?

# NOTE! configure detects necessary libraries for extension modules
# and will build them without these options enabled (and there aren't
# (currently) any --without options to disable them)
#
# It's possible to build the extension modules independently of the
# main distribution, so there could be snobol4-ffi, snobol4-sqlite3
# ports, BUT you need to cd to a subdir before running make.
#
# Not including Tcl, would need a RADIO selector for tcl version, and
# configure would need to be run with --with-tcl=/path/to/tclConfig.sh

OPTIONS_DEFINE=		FFI SQLITE3 DOCS
OPTIONS_DEFAULT=	FFI SQLITE3 DOCS

FFI_DESC=		Foreign Function Interface module
SQLITE3_DESC=		SQLite version 3 module

DOCS_CONFIGURE_WITH=	docs

FFI_LIB_DEPENDS=	libffi.so:devel/libffi
SQLITE3_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

post-patch:
	@${REINPLACE_CMD} 's/CFLAGS /CFLAGS $$CPPFLAGS /' ${WRKSRC}/config/check

.include <bsd.port.mk>
