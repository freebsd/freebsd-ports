# New ports collection makefile for:	SWIG
# Date created:			19 April 1996
# Whom:				jkh
#
# $FreeBSD$
#

PORTNAME=	swig
PORTVERSION=	1.3.11
CATEGORIES=	devel perl5 python ruby tcl82
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.rge.com/pub/languages/swig/ \
		ftp://ftp.mcc.ac.uk/pub/mvc/swig/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=		autoconf:${PORTSDIR}/devel/autoconf

VER=		${PORTVERSION:R}

SWIG_LANGUAGES?=	guile perl php4 python ruby tcl
.for lang in ${SWIG_LANGUAGES}
WANT_SWIG_${lang:U}=	yes
.endfor

.if defined(WANT_SWIG_GUILE)
BUILD_DEPENDS+=		guile:${PORTSDIR}/lang/guile
PLIST_SUB+=		WANT_SWIG_GUILE=""
.else
PLIST_SUB+=		WANT_SWIG_GUILE="@comment "
.endif
.if defined(WANT_SWIG_PERL)
USE_PERL5=		yes
PLIST_SUB+=		WANT_SWIG_PERL=""
.else
PLIST_SUB+=		WANT_SWIG_PERL="@comment "
.endif
.if defined(WANT_SWIG_PHP4)
# We need both mod_php4 and php4
BUILD_DEPENDS+=		${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4 \
			php:${PORTSDIR}/lang/php4
PLIST_SUB+=		WANT_SWIG_PHP4=""
.else
PLIST_SUB+=		WANT_SWIG_PHP4="@comment "
.endif
.if defined(WANT_SWIG_PYTHON)
USE_PYTHON=		yes
PYTHON_NO_DEPENDS=	yes
BUILD_DEPENDS+=		${PYTHON_CMD}:${PYTHON_PORTSDIR}
CONFIGURE_ARGS+=	--with-pyincl=${PYTHON_INCLUDEDIR} \
			--with-pylib=${PYTHON_LIBDIR}
PLIST_SUB+=		WANT_SWIG_PYTHON=""
.else
PLIST_SUB+=		WANT_SWIG_PYTHON="@comment "
.endif
.if defined(WANT_SWIG_RUBY)
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
PLIST_SUB+=		WANT_SWIG_RUBY=""
.else
PLIST_SUB+=		WANT_SWIG_RUBY="@comment "
.endif
.if defined(WANT_SWIG_TCL)
BUILD_DEPENDS+=		${LOCALBASE}/bin/tclsh8.2:${PORTSDIR}/lang/tcl82
CONFIGURE_ARGS+=	--with-tclincl=${LOCALBASE}/include/tcl8.2/ \
			--with-tcllib=${LOCALBASE}/lib/tcl8.2/
PLIST_SUB+=		WANT_SWIG_TCL=""
.else
PLIST_SUB+=		WANT_SWIG_TCL="@comment "
.endif

INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:U}
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -fpic -DPIC"
ALL_TARGET=	swig runtime
PLIST_SUB+=	VER="${VER}"

post-patch:
	${PERL} -i.orig -p \
		-e 's:/usr/local(/include/php)\b:${LOCALBASE}$$1:;' \
		-e 's:(/php_config\.h)\b:/main$$1:;' \
		${WRKSRC}/configure.in ${WRKSRC}/configure
	${PERL} -i.orig -p \
		-e 's:^(LIBS\s+=\s+):$${1}libswigphp4\$$(RELEASESUFFIX).la :;' \
		${WRKSRC}/Runtime/Makefile.in

post-install:
	${LN} -f ${PREFIX}/bin/swig ${PREFIX}/bin/swig${VER}

.include <bsd.port.mk>
