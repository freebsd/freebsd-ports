# New ports collection makefile for:	SWIG
# Date created:			19 April 1996
# Whom:				jkh
#
# $FreeBSD$
#

PORTNAME=	swig
PORTVERSION=	${VER}p5
PORTREVISION=	9
CATEGORIES=	devel perl5 python tcl
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.mcc.ac.uk/pub/mvc/swig/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simplified Wrapper and Interface Generator

DEPRECATED=	use devel/swig13 instead, last release of 1.1 was 8 years ago
EXPIRATION_DATE=2008-05-10

BUILD_DEPENDS=	${PYTHON_CMD}:${PYTHON_PORTSDIR} \
		${LOCALBASE}/bin/tclsh8.4:${PORTSDIR}/lang/tcl84

VER=		1.1

USE_PERL5=	yes
USE_PYTHON=	yes
PYTHON_NO_DEPENDS=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:U}${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -DPIC" PYTHON_VERSION=${PYTHON_VERSION}
CONFIGURE_ARGS=	--with-tclincl=${LOCALBASE}/include/tcl8.4/ \
		--with-tcllib=${LOCALBASE}/lib/tcl8.4/ \
		--with-pyincl=${PYTHONPREFIX_INCLUDEDIR} \
		--with-pylib=${LOCALBASE}/lib
ALL_TARGET=	all runtime

MAN1=		swig.1
PLIST_SUB=	VER="${VER}"

NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "sparc64"
CFLAGS+=	-fpic
.endif

post-install:
	${LN} -f ${PREFIX}/bin/swig ${PREFIX}/bin/swig${VER}

.include <bsd.port.post.mk>
