# New ports collection makefile for:	a2ps-j
# Version required:	1.41
# Date created:		16 Nov 1996
# Whom:			SAITO Itsuro <saito@miv.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.3 1997/09/14 21:34:29 max Exp $
#

DISTNAME=	a2ps.pl-1.41
PKGNAME=	ja-a2ps-1.41
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	# None

MAINTAINER=	saito@miv.t.u-tokyo.ac.jp

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/a2ps.pl-1.41 ${PREFIX}/bin/a2ps-j

.include <bsd.port.mk>
