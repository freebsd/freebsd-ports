# New ports collection makefile for:	Firebird
# Date created:		20 December 2000
# Whom:			Geoffrey C. Speicher <geoff@sea-incorporated.com>
#
# $FreeBSD$
#

PORTNAME=	firebird
PORTVERSION=	1.0.2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}	\
		http://www.aims.com.au/chris/firebird/
MASTER_SITE_SUBDIR=firebird
DISTFILES=	bootkit-1.0.2.908.tar.gz \
		interbase0.9-4-v5examples.tar.gz \
		Firebird-1.0.2.908.src.tar.gz

MAINTAINER=	chris@aims.com.au

WRKSRC=		${WRKDIR}/firebird-1.0.2.908
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/firebird/lib
MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_REINPLACE=	yes

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

pre-everything:
	@${ECHO_MSG} "NOTE: If the work directory is on an NFS mount, you will"
	@${ECHO_MSG} "require NFS client locking support for the build to"
	@${ECHO_MSG} "succeed. Currently this is only available on FreeBSD 5.0"
	@${ECHO_MSG} "or greater."
.if !defined(BATCH)
	@sleep 5
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@(								\
	cd ${WRKDIR}; ${TAR} -zxf					\
		 ${DISTDIR}/Firebird-1.0.2.908.src.tar.gz;		\
	cd firebird-1.0.2.908;						\
	${TAR} -zxf ${DISTDIR}/bootkit-1.0.2.908.tar.gz;		\
	${CP} -f msgs/msg.gbak misc/msg.gbak				\
	)

post-patch:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE}
.if ${OSVERSION} >= 430001 && ${OSVERSION} < 500000 || ${OSVERSION} >= 500016
	@${REINPLACE_CMD} -e 's,\-ldescrypt,\-lcrypt,g' \
		 ${WRKSRC}/builds/original/prefix.freebsd
.else
	@${REINPLACE_CMD} -e 's,^crypt_set_format.*,,' ${WRKSRC}/jrd/enc.c
.endif

do-configure:
	@(								\
	cd ${WRKDIR}/firebird-1.0.2.908;				\
	INTERBASE=${WRKDIR}/firebird-1.0.2.908/interbase; export INTERBASE; \
	REFDBPATH=${WRKDIR}/firebird-1.0.2.908/refDatabases; export REFDBPATH; \
	NOPROMPT_SETUP=yes; export NOPROMPT_SETUP;			\
	FIREBIRD_64_BIT_IO=yes; export FIREBIRD_64_BIT_IO;		\
	${SH} Configure.sh PROD FREEBSD;				\
	)

do-build:
	@(								\
	${REINPLACE_CMD} -e 's,opt,usr,'				\
		 ${WRKSRC}/firebird/install/linux/misc/ibmgr;		\
	${LN} -sf ${WRKDIR}/firebird-1.0.2.908/refDatabases/jrd/isc.gdb	\
		 ${WRKDIR}/firebird-1.0.2.908/interbase/isc4.gdb;	\
	${LN} -sf ${WRKDIR}/firebird-1.0.2.908/refDatabases/msgs/msg.gdb \
		 ${WRKDIR}/firebird-1.0.2.908/msg.gdb;			\
	cd ${WRKDIR}/firebird-1.0.2.908;				\
	INTERBASE=${WRKDIR}/firebird-1.0.2.908/interbase; export INTERBASE; \
	REFDBPATH=${WRKDIR}/firebird-1.0.2.908/refDatabases; export REFDBPATH; \
	${CP} ${PKGDIR}/files/buildit.sh ${WRKDIR}/firebird-1.0.2.908;	\
	${SH} buildit.sh;						\
	)

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@(								\
	cd ${WRKDIR}/firebird-1.0.2.908;				\
	${RM} ${WRKDIR}/firebird-1.0.2.908/interbase/isc4_tmp.gdb || ${TRUE}; \
	${RM} ${WRKDIR}/firebird-1.0.2.908/interbase/lib/gds.so.1 || ${TRUE}; \
	${TOUCH} interbase/interbase.log;				\
	${CP} -Rp interbase ${PREFIX}/firebird;				\
	${RM} ${PREFIX}/firebird/install;				\
	${RM} ${PREFIX}/firebird/lib/libgds.so.1.0;			\
	${RM} ${PREFIX}/firebird/lib/libgds_pyxis.a;			\
	${LN} -fs gds.so ${PREFIX}/firebird/lib/libgds.so.1;		\
	cd ${PREFIX}/firebird/examples;					\
	${TAR} -xzf ${DISTDIR}/interbase0.9-4-v5examples.tar.gz;	\
	${CP} ${FILESDIR}/RELNOTES ${PREFIX}/firebird/;			\
	${CP} ${WRKSRC}/firebird/install/linux/misc/ibmgr		\
		${PREFIX}/firebird/bin;					\
	)

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
