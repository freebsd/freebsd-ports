# New ports collection makefile for:	skk
# Version required:	8.6
# Date created:		10 Aug 1996
# Whom:			Hidekazu Kuroki <hidekazu@cs.titech.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/08/19 11:50:33 asami Exp $
#

DISTNAME=	skk8.6
PKGNAME=	jp-skk-8.6
CATEGORIES+=	japanese
MASTER_SITES=	ftp://ftp.cs.keio.ac.jp/pub/misc/skk/ \
		ftp://ftp.tohoku.ac.jp/mirror/skk/8.6/

MAINTAINER=	hidekazu@cs.titech.ac.jp

# Don't RUN_DEPENDS on mule because we don't know which version the
# user would want.  We can't omit the BUILD_DEPENDS because it needs
# to byte-compile .el files.
BUILD_DEPENDS=	mule:${PORTSDIR}/editors/mule

NO_WRKSUBDIR=	yes

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/skkserv.sh

post-install:
	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
		echo "Installing ${STARTUP_SCRIPT} file."; \
		echo "#!/bin/sh" > ${STARTUP_SCRIPT}; \
		echo "if [ -f ${PREFIX}/bin/SKK/skkserv ]; then" >> \
			${STARTUP_SCRIPT}; \
		echo "	echo -n ' skkserv'; ${PREFIX}/bin/SKK/skkserv" >> \
			${STARTUP_SCRIPT}; \
		echo "fi" >> ${STARTUP_SCRIPT}; \
		chmod 755 ${STARTUP_SCRIPT}; \
	fi

.include <bsd.port.mk>
