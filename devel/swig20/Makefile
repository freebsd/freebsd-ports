# New ports collection makefile for:	SWIG
# Date created:			19 April 1996
# Whom:				jkh
#
# $FreeBSD$
#

PORTNAME=	swig
PORTVERSION=	${VER}a5
PORTREVISION=	4
CATEGORIES=	devel perl5 python ruby tcl82
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.rge.com/pub/languages/swig/ \
		ftp://ftp.mcc.ac.uk/pub/mvc/swig/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_CMD}:${PYTHON_PORTSDIR} \
		${LOCALBASE}/bin/tclsh8.2:${PORTSDIR}/lang/tcl82

VER=		1.3

USE_PERL5=	yes
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
PYTHON_VERSION?=	python1.5
PYTHON_NO_DEPENDS=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/SWIG${PORTVERSION}
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -fpic -DPIC"
CONFIGURE_ARGS=	--with-tclincl=${PREFIX}/include/tcl8.2/ \
		--with-tcllib=${PREFIX}/lib/tcl8.2/
ALL_TARGET=	swig runtime
PLIST_SUB=	VER="${VER}"

post-install:
	${LN} ${PREFIX}/bin/swig ${PREFIX}/bin/swig${VER}

.include <bsd.port.mk>
