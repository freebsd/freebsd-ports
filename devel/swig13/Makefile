# New ports collection makefile for:	SWIG
# Date created:			19 April 1996
# Whom:				jkh
#
# $FreeBSD$
#

PORTNAME=	swig
PORTVERSION=	1.3.9
CATEGORIES=	devel perl5 python ruby tcl82
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.rge.com/pub/languages/swig/ \
		ftp://ftp.mcc.ac.uk/pub/mvc/swig/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=		autoconf:${PORTSDIR}/devel/autoconf

VER=		${PORTVERSION:R}

SWIG_LANGUAGES?=	guile perl python ruby tcl
.for lang in ${SWIG_LANGUAGES}
WANT_SWIG_${lang:U}=	yes
.endfor

.if defined(WANT_SWIG_GUILE)
BUILD_DEPENDS+=		guile:${PORTSDIR}/lang/guile
.endif
.if defined(WANT_SWIG_PERL)
USE_PERL5=		yes
.endif
.if defined(WANT_SWIG_PYTHON)
USE_PYTHON=		yes
PYTHON_NO_DEPENDS=	yes
BUILD_DEPENDS+=		${PYTHON_CMD}:${PYTHON_PORTSDIR}
CONFIGURE_ARGS+=	--with-pyincl=${PYTHON_INCLUDEDIR} \
			--with-pylib=${PYTHON_LIBDIR}
.endif
.if defined(WANT_SWIG_RUBY)
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
.endif
.if defined(WANT_SWIG_TCL)
BUILD_DEPENDS+=		${LOCALBASE}/bin/tclsh8.2:${PORTSDIR}/lang/tcl82
CONFIGURE_ARGS+=	--with-tclincl=${LOCALBASE}/include/tcl8.2/ \
			--with-tcllib=${LOCALBASE}/lib/tcl8.2/
.endif

INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:U}
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -fpic -DPIC"
ALL_TARGET=	swig runtime
PLIST_SUB=	VER="${VER}"

post-install:
	${LN} -f ${PREFIX}/bin/swig ${PREFIX}/bin/swig${VER}

.include <bsd.port.mk>
