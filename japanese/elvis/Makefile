# New ports collection makefile for:    elvis + japanese patch
# Version required:     1.8 pl 4 + j 1.1
# Date created:         5 October 1995
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1995/10/18 11:18:58 asami Exp $
#

DISTNAME=       elv18src
PKGNAME=        jp-elvis-1.8.4
CATEGORIES+=    japanese editors
MASTER_SITES=   ftp://ftp.cs.pdx.edu/pub/elvis/
EXTRACT_SUFX=	.tgz

PATCH_SITES=    ftp://ftp.foretune.co.jp/pub/tools/jelvis/
PATCHFILES=     jelvis1.8p4-j1.1.tar.Z
PATCH_DIST_STRIP=       -p1

MAINTAINER=     sanpei@yy.cs.keio.ac.jp

LIB_DEPENDS=	canna\\.1\\.:${PORTSDIR}/japanese/Canna

NO_WRKSUBDIR=	yes

STARTUP_SCRIPT= ${PREFIX}/etc/rc.d/jp-elvis.sh
do-configure:
	@cp ${WRKSRC}/Makefile.mix ${WRKSRC}/Makefile

post-install:
	if [ ! -d ${PREFIX}/share/doc/jp-elvis ]; then \
		mkdir -p ${PREFIX}/share/doc/jp-elvis; \
	fi
	${INSTALL_DATA} ${WRKSRC}/README.j18 ${PREFIX}/share/doc/jp-elvis
	@/bin/sh ${PKGDIR}/REQ ${PKGNAME} INSTALL
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		echo "Installing ${STARTUP_SCRIPT} startup file.";	\
		echo '#!/bin/sh' > ${STARTUP_SCRIPT};			\
		echo 'virecovery=`echo /var/tmp/elv_*`'			\
			>> ${STARTUP_SCRIPT};				\
		echo 'if [ "$$virecovery" != '"'/var/tmp/elv_*' ]; then"	\
			>> ${STARTUP_SCRIPT};				\
		echo "	echo 'Recovering jp-elvis editor sessions'"	\
			>> ${STARTUP_SCRIPT};				\
		echo '	for i in $$virecovery; do'			\
			>> ${STARTUP_SCRIPT};				\
		echo "		${PREFIX}/bin/elvprsv "'$$i'		\
			>> ${STARTUP_SCRIPT};				\
		echo '	done'						\
			>> ${STARTUP_SCRIPT};				\
		echo 'fi' >> ${STARTUP_SCRIPT};				\
		chmod 755 ${STARTUP_SCRIPT};				\
		chown bin.bin ${STARTUP_SCRIPT};                        \
	fi

.include <bsd.port.mk>
