# New ports collection makefile for:	jcode.pl
# Version required:	2.10
# Date created:		20 February 1998
# Whom:			sada
#
# $Id: Makefile,v 1.1.1.1 1998/06/29 19:42:15 max Exp $
#

DISTNAME=	jcode.pl-2.10
PKGNAME=	ja-jcode.pl-2.10
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=

MAINTAINER=	sada@e-mail.ne.jp

NO_WRKSUBDIR=		yes
NO_BUILD=		yes
EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.

INSTALLDIR=	${PREFIX}/lib/perl

do-install:
	@${MKDIR} ${INSTALLDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${INSTALLDIR}/jcode.pl

.include <bsd.port.mk>
