# New ports collection makefile for:	SWIG
# Date created:			19 April 1996
# Whom:				jkh
#
# $FreeBSD$
#

PORTNAME=	swig
PORTVERSION=	${VER}p5
PORTREVISION=	3
CATEGORIES=	devel perl5 python tcl82
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.rge.com/pub/languages/swig/${VER}/ \
		ftp://ftp.mcc.ac.uk/pub/mvc/swig/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_CMD}:${PYTHON_PORTSDIR} \
		${LOCALBASE}/bin/tclsh8.2:${PORTSDIR}/lang/tcl82

VER=		1.1

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
PLIST_SUB=	VER="${VER}"

post-install:
	${LN} ${PREFIX}/bin/swig ${PREFIX}/bin/swig${VER}

.include <bsd.port.mk>
