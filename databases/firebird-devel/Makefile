# New ports collection makefile for:	Firebird-devel
# Date created:		03 December 2001
# Whom:			Chris Knight <chris@aims.com.au>
#
# $FreeBSD$
#

PORTNAME=	firebird
PORTVERSION=	1.0.r2
CATEGORIES=	databases
MASTER_SITES=	http://www.aims.com.au/chris/
MASTER_SITE_SUBDIR=firebird
DISTFILES=	bootkit-RC2.tar.gz \
		interbase0.9-4-v5examples.tar.gz \
		Firebird-1.0.0-RC2-FreeBSD.tar.gz

MAINTAINER=	chris@aims.com.au

WRKSRC=		${WRKDIR}/interbase
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/firebird/lib
MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_REINPLACE=	yes
USE_PERL5=	yes

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKDIR}
	@(								\
	cd ${WRKDIR}; ${TAR} -zxf					\
		 ${DISTDIR}/Firebird-1.0.0-RC2-FreeBSD.tar.gz;		\
	cd interbase; ${TAR} -zxf ${DISTDIR}/bootkit-RC2.tar.gz;	\
	${CP} ${FILESDIR}/boot.freebsd ${WRKDIR}/interbase/;		\
	${CP} ${FILESDIR}/make.freebsd ${WRKDIR}/interbase/;		\
	${CP} ${FILESDIR}/buildBootDatabases ${WRKDIR}/interbase/;	\
	${CP} msgs/msg.gbak misc/msg.gbak				\
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
	cd ${WRKDIR}/interbase;						\
	INTERBASE=${WRKDIR}/interbase/interbase; export INTERBASE;	\
	REFDBPATH=${WRKDIR}/refDatabases; export REFDBPATH;		\
	${SH} buildBootDatabases;					\
	NOPROMPT_SETUP=yes; export NOPROMPT_SETUP;			\
	FIREBIRD_64_BIT_IO=yes; export FIREBIRD_64_BIT_IO;		\
	${CAT} builds_win32/original/build_no.ksh | ${TR} -d '\r'	\
		> builds_win32/original/build_no.ksh.fix;		\
	${MV} builds_win32/original/build_no.ksh.fix			\
		 builds_win32/original/build_no.ksh;			\
	${SH} Configure.sh PROD FREEBSD;				\
	)

do-build:
	@(								\
	 ${ECHO_CMD} '#!/bin/sh'; ${ECHO_CMD}				\
	'[ -d ${LDCONFIG_RUNLIST} ] && ${LDCONFIG} -m ${LDCONFIG_RUNLIST}'; \
	) > ${WRKDIR}/000.${PORTNAME}.sh
	@(								\
	${LN} -sf ${WRKDIR}/refDatabases/jrd/isc.gdb			\
		 ${WRKDIR}/interbase/interbase/isc4.gdb;		\
	cd ${WRKDIR}/interbase;						\
	INTERBASE=${WRKDIR}/interbase/interbase; export INTERBASE;	\
	REFDBPATH=${WRKDIR}/refDatabases; export REFDBPATH;		\
	${SH} boot.freebsd;						\
	)

do-install:
	@(								\
	cd ${WRKDIR}/interbase;						\
	${RM} ${WRKDIR}/interbase/interbase/isc4_tmp.gdb;		\
	${CP} /dev/null interbase/interbase.log;			\
	${CP} -Rp interbase ${PREFIX}/firebird;				\
	${RM} ${PREFIX}/firebird/install;				\
	${RM} ${PREFIX}/firebird/lib/libgds.so.1.0;			\
	${LN} -fs gds.so ${PREFIX}/firebird/lib/libgds.so.1;		\
	cd ${PREFIX}/firebird/examples;					\
	${TAR} -xzf ${DISTDIR}/interbase0.9-4-v5examples.tar.gz;	\
	${CP} ${FILESDIR}/RELNOTES ${PREFIX}/firebird/;			\
	${INSTALL_SCRIPT} ${WRKDIR}/000.${PORTNAME}.sh ${PREFIX}/etc/rc.d/ \
	)

.include <bsd.port.post.mk>
