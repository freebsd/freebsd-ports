# New ports collection makefile for:	a2ps-j
# Date created:		16 Nov 1996
# Whom:			SAITO Itsuro <saito@miv.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	a2ps
PORTVERSION=	1.45
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
DISTNAME=	${PORTNAME}.pl-${PORTVERSION}
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text file to postscript converter (with Japanese support)

PLIST_FILES=	bin/a2ps-j
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	./a2ps-j
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/a2ps-j ${PREFIX}/bin

.include <bsd.port.mk>
