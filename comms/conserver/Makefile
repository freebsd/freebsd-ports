# Ports collection makefile for:    conserver
# Version required:     5.21-Beta
# Date created:         22 November 1997
# Whom:                 Peter Wemm <peter@netplex.com.au>
#
# $Id$
#

DISTNAME=	conserver-5.21-Beta
PKGNAME=	conserver-5.21
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.uu.net/vendor/bitsko/config-mgmt/ \
		ftp://unix.hensa.ac.uk/mirrors/uunet/vendor/bitsko/config-mgmt/
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	peter@FreeBSD.org

EXTRACT_CMD=	zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
NO_WRKSUBDIR=	yes
NO_CONFIGURE=	yes

# Set this to where you want console(8) to connect to by default
MAKE_ENV+=	DEFAULTHOST="localhost"

post-extract:
	cp ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
