# New ports collection makefile for:	Firebird
# Date created:		20 December 2000
# Whom:			Geoffrey C. Speicher <geoff@sea-incorporated.com>
#
# $FreeBSD$
#

PORTNAME=	firebird
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://firebird.sourceforge.net/download/ \
		http://www.aims.com.au/chris/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=firebird
DISTFILES=	bootkit-1.0.0.796.tar.gz \
		bootkit-freebsd-1.0.0.796.tar.gz \
		interbase0.9-4-v5examples.tar.gz \
		Firebird-1.0.0.796.src.tar.gz

MAINTAINER=	chris@aims.com.au

WRKSRC=		${WRKDIR}/firebird-1.0.0.796
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/firebird/lib
MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_REINPLACE=	yes

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKDIR}
	@(								\
	cd ${WRKDIR}; ${TAR} -zxf					\
		 ${DISTDIR}/Firebird-1.0.0.796.src.tar.gz;		\
	cd firebird-1.0.0.796;						\
	${TAR} -zxf ${DISTDIR}/bootkit-1.0.0.796.tar.gz;		\
	${TAR} -zxf ${DISTDIR}/bootkit-freebsd-1.0.0.796.tar.gz;	\
	${CP} -f msgs/msg.gbak misc/msg.gbak				\
	)

post-patch:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE}
.if ${OSVERSION} >= 500016 || ${OSVERSION} >= 430001
	@${REINPLACE_CMD} -e 's,\-ldescrypt,\-lcrypt,g' \
		 ${WRKSRC}/builds/original/prefix.freebsd
.else
	@${REINPLACE_CMD} -e 's,^crypt_set_format.*,,' ${WRKSRC}/jrd/enc.c
.endif

do-configure:
	@(								\
	cd ${WRKDIR}/firebird-1.0.0.796;				\
	INTERBASE=${WRKDIR}/firebird-1.0.0.796/interbase; export INTERBASE; \
	REFDBPATH=${WRKDIR}/firebird-1.0.0.796/refDatabases; export REFDBPATH; \
	${SH} buildBootDatabases;					\
	NOPROMPT_SETUP=yes; export NOPROMPT_SETUP;			\
	FIREBIRD_64_BIT_IO=yes; export FIREBIRD_64_BIT_IO;		\
	${CAT} builds_win32/original/build_no.ksh | ${TR} -d '\r'	\
		> builds_win32/original/build_no.ksh.fix;		\
	${MV} -f builds_win32/original/build_no.ksh.fix			\
		 builds_win32/original/build_no.ksh;			\
	${SH} Configure.sh PROD FREEBSD;				\
	)

do-build:
	@(								\
	${REINPLACE_CMD} -e 's,opt,usr,'				\
		 ${WRKSRC}/firebird/install/linux/misc/ibmgr;		\
	${LN} -sf ${WRKDIR}/firebird-1.0.0.796/refDatabases/jrd/isc.gdb	\
		 ${WRKDIR}/firebird-1.0.0.796/interbase/isc4.gdb;	\
	${LN} -sf ${WRKDIR}/firebird-1.0.0.796/refDatabases/msgs/msg.gdb \
		 ${WRKDIR}/firebird-1.0.0.796/msg.gdb;			\
	cd ${WRKDIR}/firebird-1.0.0.796;				\
	INTERBASE=${WRKDIR}/firebird-1.0.0.796/interbase; export INTERBASE; \
	REFDBPATH=${WRKDIR}/firebird-1.0.0.796/refDatabases; export REFDBPATH; \
	${CP} ${PKGDIR}/files/buildit.sh ${WRKDIR}/firebird-1.0.0.796;	\
	${SH} buildit.sh;						\
	)

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@(								\
	cd ${WRKDIR}/firebird-1.0.0.796;				\
	${RM} ${WRKDIR}/firebird-1.0.0.796/interbase/isc4_tmp.gdb || ${TRUE}; \
	${RM} ${WRKDIR}/firebird-1.0.0.796/interbase/lib/gds.so.1 || ${TRUE}; \
	${CP} /dev/null interbase/interbase.log;			\
	${CP} -Rp interbase ${PREFIX}/firebird;				\
	${RM} ${PREFIX}/firebird/install;				\
	${RM} ${PREFIX}/firebird/lib/libgds.so.1.0;			\
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
