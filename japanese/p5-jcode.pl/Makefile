# New ports collection makefile for:	p5-jcode.pl
# Date created:				26 Jun 1998
# Whom:					SADA Kenji <sada@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jcode.pl
PORTVERSION=	2.11
CATEGORIES=	japanese perl5
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 library for Japanese character code conversion

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_WRKSUBDIR=	YES
NO_BUILD=	YES
USE_PERL5=	YES
PLIST_SUB=	INSTALL_BASE=${INSTALL_BASE}

INSTALL_BASE=	lib/perl5/site_perl/${PERL_VER}
INSTALL_DIR=	${PREFIX}/${INSTALL_BASE}

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

do-install:
	${MKDIR} ${INSTALL_DIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${INSTALL_DIR}/jcode.pl

.include <bsd.port.post.mk>
