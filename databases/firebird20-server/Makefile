# New ports collection makefile for:	Firebird
# Date created:		20 December 2000
# Whom:			Geoffrey C. Speicher <geoff@sea-incorporated.com>
#
# $FreeBSD$
#

PORTNAME=	firebird
PORTVERSION=	0.9
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://firebird.sourceforge.net/download/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=firebird
DISTFILES=	firebird-boot-kit.tar.gz \
		interbase0.9-4-v5examples.tar.gz \
		interbase0.9-4src.tar.gz

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
	cd ${WRKDIR}; ${TAR} -xzf ${DISTDIR}/interbase0.9-4src.tar.gz;	\
	cd interbase; ${TAR} -xzf ${DISTDIR}/firebird-boot-kit.tar.gz;	\
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
	${SH} setup_dirs.boot FREEBSD PROD ${WRKDIR}/refDatabases boot;	\
	)

do-build:
	@(								\
	 ${ECHO_CMD} '#!/bin/sh'; ${ECHO_CMD}				\
	'[ -d ${LDCONFIG_RUNLIST} ] && ${LDCONFIG} -m ${LDCONFIG_RUNLIST}'; \
	) > ${WRKDIR}/000.${PORTNAME}.sh
	@(								\
	cd ${WRKDIR}/interbase;						\
	INTERBASE=${WRKDIR}/interbase/interbase; export INTERBASE;	\
	REFDBPATH=${WRKDIR}/refDatabases; export REFDBPATH;		\
	${SH} boot.freebsd;						\
	)

do-install:
	@(								\
	cd ${WRKDIR}/interbase;						\
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
