# New ports collection makefile for:	a2ps-j
# Date created:		16 Nov 1996
# Whom:			SAITO Itsuro <saito@miv.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	a2ps
PORTVERSION=	1.44
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
DISTFILES=	${PORTNAME}.pl-${PORTVERSION}

MAINTAINER=	saito@miv.t.u-tokyo.ac.jp

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/a2ps.pl-1.44 ${PREFIX}/bin/a2ps-j

.include <bsd.port.mk>
