# New ports collection makefile for:    SWIG
# Date created:         19 April 1996
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	swig
PORTVERSION=	1.1p5
PORTREVISION=	1
CATEGORIES=	devel perl5 python tcl82
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.rge.com/pub/languages/swig/1.1/ \
		ftp://ftp.mcc.ac.uk/pub/mvc/swig/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_CMD}:${PYTHON_PORTSDIR} \
		${LOCALBASE}/bin/tclsh8.2:${PORTSDIR}/lang/tcl82

USE_PERL5=	yes
PYTHON_VERSION?=	python1.5
PYTHON_NO_DEPENDS?=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/SWIG${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclincl=${PREFIX}/include/tcl8.2/ \
		--with-tcllib=${PREFIX}/lib/tcl8.2/

ALL_TARGET=	all runtime

MAN1=		swig.1

.include <bsd.port.mk>
