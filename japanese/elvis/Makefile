# New ports collection makefile for:    elvis + japanese patch
# Date created:         5 October 1995
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	elvis
PORTVERSION=	1.8.4
CATEGORIES=    japanese editors
MASTER_SITES=   ftp://ftp.cs.pdx.edu/pub/elvis/
EXTRACT_SUFX=	.tgz
DISTNAME=	${PORTNAME}-1.8

PATCH_SITES=    ftp://ftp.foretune.co.jp/pub/tools/jelvis/
PATCHFILES=     j${PORTNAME}1.8p4-j1.1.tar.Z

MAINTAINER=     sanpei@sanpei.org

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna

NO_WRKSUBDIR=	yes
PATCH_DIST_STRIP=       -p1
MAN1=		elvis.1 ctags.1 ref.1 elvrec.1 elvprsv.1

STARTUP_SCRIPT= ${PREFIX}/etc/rc.d/ja-elvis.sh

do-configure:
	@${CP} ${WRKSRC}/Makefile.mix ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${PREFIX}/share/doc/ja-elvis
	${INSTALL_DATA} ${WRKSRC}/README.j18 ${PREFIX}/share/doc/ja-elvis
	@${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file.";	\
		${ECHO} '#!/bin/sh' > ${STARTUP_SCRIPT};			\
		${ECHO} 'virecovery=`${ECHO} /var/tmp/elv_*`'			\
			>> ${STARTUP_SCRIPT};				\
		${ECHO} 'if [ "$$virecovery" != '"'/var/tmp/elv_*' ]; then"	\
			>> ${STARTUP_SCRIPT};				\
		${ECHO} "	${ECHO} 'Recovering ja-elvis editor sessions'"	\
			>> ${STARTUP_SCRIPT};				\
		${ECHO} '	for i in $$virecovery; do'			\
			>> ${STARTUP_SCRIPT};				\
		${ECHO} "		${PREFIX}/bin/elvprsv "'$$i'		\
			>> ${STARTUP_SCRIPT};				\
		${ECHO} '	done'						\
			>> ${STARTUP_SCRIPT};				\
		${ECHO} 'fi' >> ${STARTUP_SCRIPT};				\
		${CHMOD} 755 ${STARTUP_SCRIPT};				\
		${CHOWN} bin.bin ${STARTUP_SCRIPT};                        \
	fi

.include <bsd.port.mk>
