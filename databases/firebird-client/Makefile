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
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=firebird
DISTFILES=	firebird-boot-kit.tar.gz \
		interbase0.9-4-v5examples.tar.gz \
		interbase0.9-4src.tar.gz

MAINTAINER=	geoff@sea-incorporated.com

WRKSRC=		${WRKDIR}/interbase
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/firebird/lib

ONLY_FOR_ARCHS=	i386

do-extract:
	@${MKDIR} ${WRKDIR}
	@(								\
	cd ${WRKDIR}; tar zxf ${DISTDIR}/interbase0.9-4src.tar.gz;	\
	cd interbase; tar zxf ${DISTDIR}/firebird-boot-kit.tar.gz;	\
	${CP} msgs/msg.gbak misc/msg.gbak				\
	)

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
	tar zxf ${DISTDIR}/interbase0.9-4-v5examples.tar.gz;		\
	${CP} ${FILESDIR}/RELNOTES ${PREFIX}/firebird/			\
	)

.include <bsd.port.mk>
