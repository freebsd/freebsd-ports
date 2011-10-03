# New ports collection makefile for:	jcode.pl
# Date created:		20 February 1998
# Whom:			sada
#
# $FreeBSD$
#

PORTNAME=	jcode.pl
PORTVERSION=	2.13
PORTREVISION=	1
CATEGORIES=	japanese perl5
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl library for Japanese character code conversion

USE_PERL5_RUN=		yes
NO_WRKSUBDIR=		yes
NO_BUILD=		yes
EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	# none
EXTRACT_AFTER_ARGS=	${WRKDIR}/${PORTNAME}
PLIST_FILES=		${SITE_PERL_REL}/${PORTNAME}

do-install:
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME} ${PREFIX}/${SITE_PERL_REL}/

.include <bsd.port.mk>
