# New ports collection makefile for:	SWIG
# Date created:			19 April 1996
# Whom:				jkh
#
# $FreeBSD$
#

PORTNAME=	swig
PORTVERSION=	${VER}p5
PORTREVISION=	8
CATEGORIES=	devel perl5 python tcl83
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.rge.com/pub/languages/swig/${VER}/ \
		ftp://ftp.mcc.ac.uk/pub/mvc/swig/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${PYTHON_CMD}:${PYTHON_PORTSDIR} \
		${LOCALBASE}/bin/tclsh8.3:${PORTSDIR}/lang/tcl83

VER=		1.1

USE_PERL5=	yes
USE_PYTHON=	yes
PYTHON_NO_DEPENDS=	yes
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:U}${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -fpic -DPIC"
CONFIGURE_ARGS=	--with-tclincl=${LOCALBASE}/include/tcl8.3/ \
		--with-tcllib=${LOCALBASE}/lib/tcl8.3/
ALL_TARGET=	all runtime

MAN1=		swig.1
PLIST_SUB=	VER="${VER}"

NO_LATEST_LINK=	yes

post-install:
	${LN} -f ${PREFIX}/bin/swig ${PREFIX}/bin/swig${VER}

.include <bsd.port.mk>
