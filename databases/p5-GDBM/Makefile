# Created by: Nick Sayer <nsayer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GDBM
PORTVERSION=	1.14
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN/../../src
PKGNAMEPREFIX=	p5-
DISTNAME=	perl-5.14.2
DIST_SUBDIR=	perl

MAINTAINER=	perl@FreeBSD.org
COMMENT=	GNU Data Base Manager (gdbm) interface

LIB_DEPENDS=	libgdbm.so:databases/gdbm

EXTRACT_AFTER_ARGS=	${DISTNAME}/ext/GDBM_File ${DISTNAME}/t/lib

CFLAGS+=	-I${LOCALBASE}/include
USES=		perl5 tar:bzip2
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/${DISTNAME}/ext/GDBM_File

.include <bsd.port.mk>
