# New ports collection makefile for:	jcode.pl
# Date created:		20 February 1998
# Whom:			sada
#
# $FreeBSD$
#

PORTNAME=	jcode.pl
PORTVERSION=	2.10
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	# none

MAINTAINER=	sada@FreeBSD.org

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
