# New ports collection makefile for:    SWIG
# Date created:         19 April 1996
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	swig
PORTVERSION=	1.3a3
CATEGORIES=	devel python tcl82
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.rge.com/pub/languages/swig/ \
		ftp://ftp.python.org/pub/python/contrib/System/ \
		ftp://ftp.mcc.ac.uk/pub/mvc/swig/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/python:${PORTSDIR}/lang/python \
		${LOCALBASE}/bin/tclsh8.2:${PORTSDIR}/lang/tcl82

USE_PERL5=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/SWIG${PORTVERSION}
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-tclincl=${PREFIX}/include/tcl8.2/ \
		--with-tcllib=${PREFIX}/lib/tcl8.2/
ALL_TARGET=     swig runtime
PLIST_SUB+=     VER="1.3"

.include <bsd.port.mk>
