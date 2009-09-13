# ex:ts=8
# Ports collection makefile for:  ratfor
# Date created:			  Sat Aug 26, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ratfor
PORTVERSION=	1985.06
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://sepftp.stanford.edu/pub/sep-distr/  \
		${MASTER_SITE_LOCAL}  \
		http://sepwww.stanford.edu/sep/prof/
MASTER_SITE_SUBDIR=	obrien
DISTFILES=	ratfor.shar.2 local.ratfor77.shar

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Ratfor -- the Rational FORTRAN compiler

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| ${SH}
ALL_TARGET=	all tests
MAN1=		ratfor.1

USE_FORTRAN=	yes

post-patch:
	@cd ${WRKSRC} ; ${PATCH} --quiet < testw.patch
	@${REINPLACE_CMD} -e 's|%%F77%%|${F77}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratfor77 ${PREFIX}/bin
	cd ${PREFIX}/bin ; ${LN} -sf ratfor77 ratfor
	${INSTALL_MAN} ${WRKSRC}/ratfor.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
