# New ports collection makefile for:	Firebird
# Date created:		20 December 2000
# Whom:			Geoffrey C. Speicher <geoff@sea-incorporated.com>
#
# $FreeBSD$
#

PORTNAME?=	firebird
PORTVERSION=	1.5.2
PORTREVISION?=	2
CATEGORIES?=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=firebird
PKGNAMESUFFIX?=	-server
DISTNAME=	firebird-1.5.2.4731

MAINTAINER=	freebsd@galle.com.br
COMMENT?=	The open-source InterBase(tm) 6.0 spin-off (Classic version)

USE_REINPLACE=	yes
USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=	15
USE_AUTOCONF_VER=	259
USE_GCC=	3.4

PLIST_SUB=	FIREBIRD_VERSION=${PORTVERSION}

# Don't use ld for linking, use gcc
LD=	gcc

# Don't strip binary files
STRIP=

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${DISTNAME}

.if !defined(CLIENT_ONLY)
# Server part stuff
LIB_DEPENDS+=	fbembed.1:${PORTSDIR}/databases/firebird-client

AUTOGENARGS=	--prefix=${PREFIX}/firebird \
		--with-lock-manager

ALL_TARGET=	firebird_boot ref_databases msgs intl otherfiles \
		inet_server extlib

# Use own user and group when install server part
BINGRP=		firebird
BINMODE=	550
SHAREGRP=	firebird

SUB_FILES=	pkg-install pkg-message aliases.conf

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install

SERVER_BIN=	fb_inet_server fb_lock_mgr
UDF_SO=		ib_udf.so fbudf.so
UDF_SQL=	src/extlib/ib_udf.sql src/extlib/fbudf/fbudf.sql

CONFLICTS=	firebird-devel-[0-9]*
.else
# Client part stuff
AUTOGENARGS=	--prefix=${PREFIX} \
		--with-editline

ALL_TARGET=	firebird_basic libfbembed embed_gfix embed_gbak embed_isql embed_gpre \
		embed_util embed_gdef embed_qli libfbclient extlib

INSTALLS_SHLIB=	yes
LIBDATADIR=	${PREFIX}/libdata/firebird
PLIST_SUB+=	LIBDATADIR="libdata/firebird"
CLIENT_BIN=	fb_lock_print gbak gdef gds_drop gfix gpre gsec gstat isql qli

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif
.endif

.include <bsd.port.pre.mk>

.if !defined(CLIENT_ONLY)
pre-everything::
	@${ECHO_MSG} "NOTE: If the work directory is on an NFS mount, you will"
	@${ECHO_MSG} "require NFS client locking support for the build to"
	@${ECHO_MSG} "succeed. Currently this is only available on FreeBSD 5.0"
	@${ECHO_MSG} "or greater."
	@${ECHO_MSG}
	@${ECHO_MSG} "WARNING: The on-disk structure of the databases has"
	@${ECHO_MSG} "changed since version 1.0.x."
	@${ECHO_MSG} "Cancel this installation now and backup your databases"
	@${ECHO_MSG} "if you have not already done so."
.if !defined(BATCH)
	@sleep 10
.endif
.endif

post-patch:
.if !defined(CLIENT_ONLY)
	@${REINPLACE_CMD} -e 's|^\(LINK_OPTS +=.*\)$$|\1 -L${LOCALBASE}/lib|' \
		${WRKSRC}/builds/posix/Makefile.in.inet_server
.endif
	@${REINPLACE_CMD} -e 's|%%LIBDATADIR%%|${LIBDATADIR}|g' \
		${WRKSRC}/src/jrd/gds.cpp

.if !defined(CLIENT_ONLY)
pre-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}
.endif

do-configure:
	@(cd ${WRKSRC} && ${SETENV} CC=${CC} CXX=${CXX} MAKE=${GMAKE}	\
	${AUTOTOOLS_VARS} ./autogen.sh ${AUTOGENARGS})

post-configure:
	@${REINPLACE_CMD} -e 's|__attribute__ ((__unused__));||' \
		${WRKSRC}/src/dsql/parse.cpp
	@${REINPLACE_CMD} -e 's|firebird\.conf|${PREFIX}/etc/firebird.conf|g; \
			      s|root_dir + string(CONFIG_FILE)|string(CONFIG_FILE)|g' \
		${WRKSRC}/src/jrd/os/posix/config_root.cpp

do-build:
	@(cd ${WRKSRC} && ${SETENV} CC=${CC} CXX=${CXX} ${GMAKE} ${ALL_TARGET})

do-install:
.if !defined(CLIENT_ONLY)

	${MKDIR} ${PREFIX}/firebird
.for f in UDF bin help intl
	${MKDIR} ${PREFIX}/firebird/${f}
	${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/firebird/${f}
.endfor

	${INSTALL_DATA} ${WRKDIR}/aliases.conf ${PREFIX}/firebird/aliases.conf.sample
	${INSTALL_DATA} -m 660 -o firebird ${WRKSRC}/gen/firebird/security.fdb \
		${PREFIX}/firebird/security.fdb.sample
	${INSTALL_DATA} -m 0440 ${WRKSRC}/gen/firebird/help/help.fdb ${PREFIX}/firebird/help

	${INSTALL_DATA} ${UDF_SO:S!^!${WRKSRC}/gen/firebird/UDF/!} \
		${UDF_SQL:S!^!${WRKSRC}/!} ${PREFIX}/firebird/UDF

	${INSTALL_PROGRAM} -o firebird \
	   ${SERVER_BIN:S!^!${WRKSRC}/gen/firebird/bin/!} ${PREFIX}/firebird/bin
	${CHMOD} u+s ${SERVER_BIN:S!^!${PREFIX}/firebird/bin/!}

	${INSTALL_DATA} ${WRKSRC}/gen/firebird/intl/libfbintl.so ${PREFIX}/firebird/intl/fbintl

	${INSTALL_DATA} ${FILESDIR}/RELNOTES ${PREFIX}/firebird

	# runtime files (.lock, .log) still placed to ${PREFIX}/firebird 
	${CHOWN} firebird:firebird ${PREFIX}/firebird
	${CHOWN} -R firebird:firebird ${PREFIX}/firebird/help

.else
# defined CLIENT_ONLY
	${INSTALL_PROGRAM} ${CLIENT_BIN:S!^!${WRKSRC}/gen/firebird/bin/!} \
		${PREFIX}/bin

	@${MKDIR} ${PREFIX}/etc
.if !exists(${PREFIX}/etc/firebird.conf)
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/misc/firebird.conf ${PREFIX}/etc
.endif
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/misc/firebird.conf ${PREFIX}/etc/firebird.conf.sample

	${INSTALL_DATA} ${WRKSRC}/gen/firebird/lib/libib_util.so \
		${WRKSRC}/gen/firebird/lib/libfbclient.so.${PORTVERSION} \
		${WRKSRC}/gen/firebird/lib/libfbembed.so.${PORTVERSION} \
		${PREFIX}/lib

	${LN} -fs libfbclient.so.${PORTVERSION} ${PREFIX}/lib/libfbclient.so.1
	${LN} -fs libfbclient.so.1 ${PREFIX}/lib/libfbclient.so

	${LN} -fs libfbembed.so.${PORTVERSION} ${PREFIX}/lib/libfbembed.so.1
	${LN} -fs libfbembed.so.1 ${PREFIX}/lib/libfbembed.so
	${LN} -fs libfbembed.so.1 ${PREFIX}/lib/libgds.so.1
	${LN} -fs libfbembed.so.1 ${PREFIX}/lib/libgds.so

	@${MKDIR} ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/include/*.h ${PREFIX}/include

	@${MKDIR} ${LIBDATADIR}
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/*.msg ${LIBDATADIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/sql.extensions
	${INSTALL_DATA} ${WRKSRC}/doc/WhatsNew ${WRKSRC}/doc/README.* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.user ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/doc/sql.extensions/README.* ${DOCSDIR}/sql.extensions
.endif

	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/examples/v5/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
