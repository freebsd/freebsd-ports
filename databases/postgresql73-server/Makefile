# New ports collection makefile for:	postgres95
# Version required:			1.07
# Date created:				Sep 14 1996
# Whom:	      				Matthew Stein <matt@bdd.net>
#
#   $Id: Makefile,v 1.1.1.1 1996/09/23 22:40:13 jfitz Exp $

PKGNAME=	postgres95-1.07
CATEGORIES+=	databases
MASTER_SITES=	ftp://ftp.ki.net/pub/postgres95/ \
		ftp://ftp.luga.or.at/pub/postgres95/ \
		ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/ \
		ftp://cal011111.student.utwente.nl/pub/postgres95/

DISTFILES=	postgres95-1.07.tar.gz \
		flex-2.5.2.tgz
		
MAINTAINER=	matt@bdd.net

NO_PACKAGE=	yes

WRKSRC=		${WRKDIR}/postgres95/src/
MAKE_ENV+=	WRKSRC=${WRKSRC} WRKDIR=${WRKDIR}
USE_GMAKE=	yes

pre-fetch:
.if exists(/usr/lib/libc.so.3.0)
		@ ${CAT} ${FILESDIR}/md5.libc30 ${FILESDIR}/md5.all > ${FILESDIR}/md5
MASTER_SITES+=	ftp://eddie.cis.uoguelph.ca/pub/flex/ \
		ftp://ftp.teamos2.org/pub/flex/ \
		ftp://ftp.bdd.net/pub/flex/
.else
		@ ${CAT} ${FILESDIR}/md5.libc22 ${FILESDIR}/md5.all > ${FILESDIR}/md5
MASTER_SITES+=	ftp://ftp.freebsd.org/pub/FreeBSD/packages-2.1.5/All/
.endif

pre-install:
		@ ${MKDIR} -p ${PREFIX}/postgres95
		@ ${SETENV} ${MAKE_ENV} /usr/bin/perl ${SCRIPTDIR}/createuser

post-install:
.if !defined(NOMANCOMPRESS)
		@ for file in ${PREFIX}/postgres95/man/man[135l]/*; do \
			gzip -9nf $$file ; \
		done
.endif
		@ chown -R postgres:postgres ${PREFIX}/postgres95
		@ echo 'Initializing Postgres95 Databases - this may take a few minutes...'
		@ su -l postgres -c ${PREFIX}/postgres95/bin/initdb
		@ ${MKDIR} -p ${PREFIX}/etc/rc.d
		@ if [ ! -f ${PREFIX}/etc/rc.d/postgres95.sh ]; then \
			echo "Installing ${PREFIX}/etc/rc.d/postgres95.sh startup file."; \
			echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/postgres95.sh; \
			echo "[ -x ${PREFIX}/postgres95/bin/postmaster ] && su -l postgres -c ${PREFIX}/postgres95/bin/postmaster & && echo -n ' postgres95'" >> ${PREFIX}/etc/rc.d/postgres95.sh; \
			chmod 751 ${PREFIX}/etc/rc.d/postgres95.sh; \
		fi
		@ ${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/postgres95
.ifndef(BATCH)
		@ more -e ${FILESDIR}/post-install-notes
.endif

pre-clean:
		@ ${RM} -f ${FILESDIR}/md5

.include <bsd.port.mk>
