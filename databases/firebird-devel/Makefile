# New ports collection makefile for:	Firebird-devel
# Date created:		03 December 2001
# Whom:			Chris Knight <chris@aims.com.au>
#
# $FreeBSD$
#

PORTNAME=	firebird
PORTVERSION=	1.0.r1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.aims.com.au/chris/
MASTER_SITE_SUBDIR=firebird
DISTFILES=	bootkit-RC1.tar.gz \
		interbase0.9-4-v5examples.tar.gz \
		Firebird-1.0.0-RC1-FreeBSD.tar.gz

MAINTAINER=	chris@aims.com.au

WRKSRC=		${WRKDIR}/interbase
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/firebird/lib
MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKDIR}
	@(								\
	cd ${WRKDIR}; ${TAR} -zxf					\
		 ${DISTDIR}/Firebird-1.0.0-RC1-FreeBSD.tar.gz;		\
	cd interbase; ${TAR} -zxf ${DISTDIR}/bootkit-RC1.tar.gz;	\
	${CP} msgs/msg.gbak misc/msg.gbak				\
	)

post-patch:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE}
.if ${OSVERSION} >= 500016 || ${OSVERSION} >= 430001
	@${PERL} -pi -e 's,\-ldescrypt,\-lcrypt,g' \
		 ${WRKSRC}/builds/original/prefix.freebsd
.else
	@${PERL} -pi -e 's,^crypt_set_format.*,,' ${WRKSRC}/jrd/enc.c
.endif

do-configure:
	@(								\
	cd ${WRKDIR}/interbase;						\
	INTERBASE=${WRKDIR}/interbase/interbase; export INTERBASE;	\
	REFDBPATH=${WRKDIR}/refDatabases; export REFDBPATH;		\
	${SH} buildBootDatabases;					\
	${CAT} builds_win32/original/build_no.ksh | ${TR} -d '\r'	\
		> builds_win32/original/build_no.ksh.fix;		\
	${MV} builds_win32/original/build_no.ksh.fix			\
		 builds_win32/original/build_no.ksh;			\
	${SH} setup_dirs boot FREEBSD PROD ${WRKDIR}/refDatabases boot;	\
	${TOUCH} ${WRKDIR}/interbase/dsql/parse.c			\
	)

do-build:
	@(								\
	 ${ECHO} '#!/bin/sh'; ${ECHO}					\
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
