# New ports collection makefile for:	a2ps-j
# Version required:	1.39
# Date created:		16 Nov 1996
# Whom:			SAITO Itsuro <saito@miv.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	a2ps-1.39
PKGNAME=	jp-a2ps-1.39
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
CATEGORIES=	japanese print
EXTRACT_SUFX=	

MAINTAINER=	saito@miv.t.u-tokyo.ac.jp

EXTRACT_CMD=	cp
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.
NO_WRKSUBDIR=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/a2ps-1.39 ${PREFIX}/bin/a2ps-j

.include <bsd.port.mk>
