# New ports collection makefile for:   diffconvert
# Date created:        30 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	diffconvert
PORTVERSION=	1.2
CATEGORIES=	devel textproc
MASTER_SITES=	ftp://ftp.ilog.fr/pub/Users/haible/gnu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A converter between context diff and unidiff formats

PROGRAMS=	cd2ud cdiffreverse ud2cd udiffreverse

do-build:
.for P in ${PROGRAMS}
	${CXX} ${WRKSRC}/${P}.cc -o ${WRKSRC}/${P}
.endfor

do-install:
.for P in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/$P ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
