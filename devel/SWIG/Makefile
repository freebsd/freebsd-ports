# New ports collection makefile for:    SWIG
# Version required:     1.1p4
# Date created:         19 April 1996
# Whom:                 jkh
#
# $Id: Makefile,v 1.12 1998/06/25 06:43:28 tg Exp $
#

DISTNAME=	swig1.1p4
PKGNAME=	swig-1.1p4
CATEGORIES=	devel python tcl81
MASTER_SITES=	ftp://ftp.cs.utah.edu/pub/beazley/SWIG/ \
		ftp://ftp.rge.com/pub/languages/swig/ \
		ftp://ftp.mcc.ac.uk/pub/mvc/swig/

MAINTAINER=	erich@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/bin/python:${PORTSDIR}/lang/python \
		${PREFIX}/bin/tclsh8.1:${PORTSDIR}/lang/tcl81

USE_PERL5=	YES
WRKSRC=		${WRKDIR}/SWIG1.1p4
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-tclincl=${PREFIX}/include/tcl8.1/ \
		--with-tcllib=${PREFIX}/lib/tcl8.1/

ALL_TARGET=	all runtime

MAN1=		swig.1

.include <bsd.port.mk>
