# New ports collection makefile for:	SWIG
# Date created:			19 April 1996
# Whom:				jkh
#
# $FreeBSD$
#

PORTNAME=	swig
PORTVERSION=	1.3.21
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Simplified Wrapper and Interface Generator

BUILD_DEPENDS=		autoconf:${PORTSDIR}/devel/autoconf

VER=		${PORTVERSION:R}

# Supported languages: guile perl php4 python ruby tcl ocaml pike java
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
CATEGORIES+=		perl5
USE_PERL5=		yes
PLIST_SUB+=		WANT_SWIG_PERL=""
.else
PLIST_SUB+=		WANT_SWIG_PERL="@comment "
.endif
.if defined(WANT_SWIG_PHP4)
BUILD_DEPENDS+=		${LOCALBASE}/include/php/main/php.h:${PORTSDIR}/lang/php4
PLIST_SUB+=		WANT_SWIG_PHP4=""
.else
PLIST_SUB+=		WANT_SWIG_PHP4="@comment "
.endif
.if defined(WANT_SWIG_PYTHON)
CATEGORIES+=		python
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
CATEGORIES+=		ruby
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
PLIST_SUB+=		WANT_SWIG_RUBY=""
.else
PLIST_SUB+=		WANT_SWIG_RUBY="@comment "
.endif
.if defined(WANT_SWIG_TCL)
CATEGORIES+=		tcl84
BUILD_DEPENDS+=		${LOCALBASE}/bin/tclsh8.4:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tclincl=${LOCALBASE}/include/tcl8.4/ \
			--with-tcllib=${LOCALBASE}/lib/tcl8.4/
PLIST_SUB+=		WANT_SWIG_TCL=""
.else
PLIST_SUB+=		WANT_SWIG_TCL="@comment "
.endif

.if defined(WANT_SWIG_OCAML)
BUILD_DEPENDS+=		${LOCALBASE}/bin/ocamlc:${PORTSDIR}/lang/ocaml
PLIST_SUB+=		WANT_SWIG_OCAML=""
.else
PLIST_SUB+=		WANT_SWIG_OCAML="@comment "
.endif

.if defined(WANT_SWIG_PIKE)
BUILD_DEPENDS+=		${LOCALBASE}/bin/pike:${PORTSDIR}/lang/pike
PLIST_SUB+=		WANT_SWIG_PIKE=""
.else
PLIST_SUB+=		WANT_SWIG_PIKE="@comment "
CONFIGURE_ARGS +=	--without-pike
.endif

.if defined(WANT_SWIG_JAVA)
CATEGORIES+=		java
USE_JAVA=	1.2+
PLIST_SUB+=		WANT_SWIG_JAVA=""
.else
PLIST_SUB+=		WANT_SWIG_JAVA="@comment "
CONFIGURE_ARGS +=	--without-java
.endif

INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:U}
USE_LIBTOOL_VER=	13
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -fpic -DPIC"
ALL_TARGET=	swig runtime
PLIST_SUB+=	VER="${VER}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Build fails on sparc64"
.endif

post-install:
# A separate swig13-runtime port might be nice
	@(cd ${INSTALL_WRKSRC}/Runtime && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

	${LN} -f ${PREFIX}/bin/swig ${PREFIX}/bin/swig${VER}

.include <bsd.port.post.mk>
