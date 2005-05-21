# New ports collection makefile for:	Firebird
# Date created:		20 December 2000
# Whom:			Geoffrey C. Speicher <geoff@sea-incorporated.com>
#
# $FreeBSD$
#

PORTNAME?=	firebird
PORTVERSION=	1.5.2
PORTREVISION=	1
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
BINOWN=		firebird
BINGRP=		firebird
BINMODE=	550
SHAREOWN=	firebird
SHAREGRP=	firebird

SUB_FILES=	pkg-install pkg-message aliases.conf

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install

CONFLICTS=	firebird-devel-[0-9]*
.else
# Client part stuff
AUTOGENARGS=	--prefix=${PREFIX} \
		--with-editline

ALL_TARGET=	firebird_basic libfbembed embed_gfix embed_gbak embed_isql embed_gpre \
		embed_util embed_gdef embed_qli libfbclient extlib

INSTALLS_SHLIB=	yes

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
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
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
	${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/firebird

.for f in UDF bin help intl
	${MKDIR} ${PREFIX}/firebird/${f}
	${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/firebird/${f}
.endfor

	${INSTALL_DATA} ${WRKDIR}/aliases.conf ${PREFIX}/firebird/aliases.conf.sample
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/security.fdb ${PREFIX}/firebird/security.fdb.sample
	${CHMOD} 660 ${PREFIX}/firebird/security.fdb.sample

	${INSTALL_DATA} ${WRKSRC}/gen/firebird/help/help.fdb ${PREFIX}/firebird/help

.for f in ib_udf.so fbudf.so
	${INSTALL_PROGRAM} ${WRKSRC}/gen/firebird/UDF/${f} ${PREFIX}/firebird/UDF
.endfor

.for f in src/extlib/ib_udf.sql src/extlib/fbudf/fbudf.sql
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/firebird/UDF
.endfor

.for f in fb_inet_server fb_lock_mgr
	${INSTALL_PROGRAM} ${WRKSRC}/gen/firebird/bin/${f} ${PREFIX}/firebird/bin
	${CHMOD} u+s ${PREFIX}/firebird/bin/${f}
.endfor

	${INSTALL_PROGRAM} ${WRKSRC}/gen/firebird/intl/libfbintl.so ${PREFIX}/firebird/intl/fbintl

	${INSTALL_DATA} ${FILESDIR}/RELNOTES ${PREFIX}/firebird

.else

.for f in fb_lock_print gbak gdef gds_drop gfix gpre gsec gstat isql qli
	${INSTALL_PROGRAM} ${WRKSRC}/gen/firebird/bin/${f} ${PREFIX}/bin
.endfor

	@${MKDIR} ${PREFIX}/etc
.if !exists(${PREFIX}/etc/firebird.conf)
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/misc/firebird.conf ${PREFIX}/etc
.endif
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/misc/firebird.conf ${PREFIX}/etc/firebird.conf.sample

	${INSTALL_PROGRAM} ${WRKSRC}/gen/firebird/lib/libfbclient.so.${PORTVERSION} ${PREFIX}/lib
	${LN} -fs libfbclient.so.${PORTVERSION} ${PREFIX}/lib/libfbclient.so.1
	${LN} -fs libfbclient.so.1 ${PREFIX}/lib/libfbclient.so

	${INSTALL_PROGRAM} ${WRKSRC}/gen/firebird/lib/libfbembed.so.${PORTVERSION} ${PREFIX}/lib
	${LN} -fs libfbembed.so.${PORTVERSION} ${PREFIX}/lib/libfbembed.so.1
	${LN} -fs libfbembed.so.1 ${PREFIX}/lib/libfbembed.so

	${LN} -fs libfbembed.so.1 ${PREFIX}/lib/libgds.so.1
	${LN} -fs libfbembed.so.1 ${PREFIX}/lib/libgds.so

	${INSTALL_PROGRAM} ${WRKSRC}/gen/firebird/lib/libib_util.so ${PREFIX}/lib

	@${MKDIR} ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/include/*.h ${PREFIX}/include

	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/firebird.msg ${DATADIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/sql.extensions
	${INSTALL_DATA} ${WRKSRC}/doc/WhatsNew ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.user ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/doc/sql.extensions/README.* ${DOCSDIR}/sql.extensions
.endif

	# Install examples
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gen/firebird/examples/v5/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
