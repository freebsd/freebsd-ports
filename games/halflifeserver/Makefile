# New ports collection makefile for:    Half-Life Dedicated Server
# Date created:				Sat Jul 15 14:27:16 SAST 2000
# Whom:					markm@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	HLDS
PORTVERSION=	3.1.0.1
CATEGORIES=	games linux
MASTER_SITES=
DISTFILES=	hlds_l3101.tar.gz cs_beta66.tar.gz
EXTRACT_ONLY=

MAINTAINER=	markm@FreeBSD.org

BUILD_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base
RUN_DEPENDS=    /compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

NO_CDROM=	"Size; the data set is much too big"
NO_BUILD=	yes
PREFIX=		/compat/linux
WRKSRC=		${WRKDIR}/hlds_l
EXTRACT_ONLY_1=	hlds_l3101.tar.gz
EXTRACT_ONLY_2=	cs_beta66.tar.gz

HLDSDIR=	/usr/games/hlds_l

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/hlds_l3101.tar.gz) \
	&& !exists(${DISTDIR}/cs_beta66.tar.gz)
IGNORE='Please go to http://www.planethalflife.com for details of how to obtain the Half-Life Dedicated Server (Linux version 3.1.0.1) and http://www.counter-strike.net for details on how to obtain the Linux port of Counter-Strike Beta 6.6. Put the files hlds_l3101.tar.gz and cs_beta66.tar.gz into the directory ${DISTDIR} and run make again.'
.endif

do-install:
	@cd ${PREFIX}/usr/games ;\
	for file in ${EXTRACT_ONLY_1}; do \
		if ! (${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$${file} ${EXTRACT_AFTER_ARGS}) ;\
		then \
			exit 1 ;\
		fi \
	done
	@cd ${PREFIX}${HLDSDIR} ;\
	for file in ${EXTRACT_ONLY_2}; do \
		if ! (${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$${file} ${EXTRACT_AFTER_ARGS}) ;\
		then \
			exit 1 ;\
		fi \
	done
	@cd ${PREFIX}${HLDSDIR} ;\
	for file in `find . -name \*.txt -or -name \*.cfg -or -name \*.inf -or -name \*.scr -or -name \*.lst -or -name \*.gam` ; do \
		${TR} -d '\r' < $${file} > $${file}.out ;\
		${MV} $${file}.out $${file} ;\
	done
	${ECHO} ${HLDSDIR} >> ${PREFIX}/etc/ld.so.conf
	${PREFIX}/bin/sh -c ldconfig

.include <bsd.port.post.mk>
