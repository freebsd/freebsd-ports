# Ports collection makefile for:    conserver
# Version required:     5.21-Beta
# Date created:         22 November 1997
# Whom:                 Peter Wemm <peter@netplex.com.au>
#
# $Id: Makefile,v 1.3 1997/11/22 15:37:11 peter Exp $
#

DISTNAME=	conserver-5.21-Beta
PKGNAME=	conserver-5.21
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.uu.net/vendor/bitsko/config-mgmt/ \
		ftp://unix.hensa.ac.uk/mirrors/uunet/vendor/bitsko/config-mgmt/
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	peter@FreeBSD.org

BROKEN=		patch

EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
NO_WRKSUBDIR=	yes
NO_CONFIGURE=	yes
MAN5=		conserver.cf.5
MAN8=		console.8 conserver.8

# Set this to where you want console(8) to connect to by default
# or use something like ``make DEFAULTHOST=myserver.mydomain.net''
DEFAULTHOST?=	localhost
MAKE_ENV+=	DEFAULTHOST="${DEFAULTHOST}"

post-extract:
	cp ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/conserver.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/conserver.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/conserver.sh; \
		echo "if [ -x /usr/local/sbin/conserver -a -f /usr/local/etc/conserver.cf ]; then" >> ${PREFIX}/etc/rc.d/conserver.sh; \
		echo "	/usr/local/sbin/conserver -d -n ; echo -n ' conserver'" >> ${PREFIX}/etc/rc.d/conserver.sh; \
		echo "fi" >> ${PREFIX}/etc/rc.d/conserver.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/conserver.sh; \
	fi

.include <bsd.port.mk>
