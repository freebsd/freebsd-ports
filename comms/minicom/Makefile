# New ports collection makefile for:    minicom
# Version required:     1.74
# Date created:         Fri Dec 01, 1995
# Whom:                 obrien@cs.ucdavis.edu
#
# $Id$
#

DISTNAME=	minicom-1.74
CATEGORIES+=	comms
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/apps/comm/ \
		ftp://ftp.yggdrasil.com/mirrors/sunsite/apps/comm/

MAINTAINER=     obrien@cs.ucdavis.edu

EXEC_DEPENDS=	rz:${PORTSDIR}/comms/rzsz \
		sz:${PORTSDIR}/comms/rzsz \
		kermit:${PORTSDIR}/comms/kermit

WRKSRC=		${WRKDIR}/${PKGNAME}/src
IS_INTERACTIVE= yes
NO_PACKAGE=	yes	# modem port etc. built in

# I believe I prefer to do this in Minicom's Makefile so as to use its macros
pre-install:
#	[ -d ${PREFIX}/etc/minicom ] || /bin/mkdir -p ${PREFIX}/etc/minicom

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/minicom.1
	gzip -9nf ${PREFIX}/man/man1/runscript.1
.endif

.include <bsd.port.mk>
