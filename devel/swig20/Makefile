# New ports collection makefile for:	SWIG
# Date created:			19 April 1996
# Whom:				jkh
#
# $FreeBSD$
#

PORTNAME=	swig
PORTVERSION=	1.3.25
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	xride@x12.dk
COMMENT=	Simplified Wrapper and Interface Generator

WANT_AUTOCONF_VER=253

VER=		${PORTVERSION:R}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

# Supported languages: guile perl php4 python ruby tcl ocaml pike java csharp
#                      allegrocl modula3 chicken
SWIG_LANGUAGES?=	guile perl php4 python ruby tcl
.for lang in ${SWIG_LANGUAGES}
WANT_SWIG_${lang:U}=	yes
.endfor

.if defined(WANT_SWIG_GUILE)
BUILD_DEPENDS+=		guile:${PORTSDIR}/lang/guile
.endif

.if defined(WANT_SWIG_PERL)
CATEGORIES+=		perl5
USE_PERL5=		yes
.endif

.if defined(WANT_SWIG_PHP4)
BUILD_DEPENDS+=		${LOCALBASE}/include/php/main/php.h:${PORTSDIR}/lang/php4
CONFIGURE_ARGS+=	--with-php4
.else
CONFIGURE_ARGS+=	--without-php4
.endif

.if defined(WANT_SWIG_PYTHON)
CATEGORIES+=		python
USE_PYTHON=		yes
PYTHON_NO_DEPENDS=	yes
BUILD_DEPENDS+=		${PYTHON_CMD}:${PYTHON_PORTSDIR}
CONFIGURE_ARGS+=	--with-pyincl=${PYTHON_INCLUDEDIR} \
			--with-pylib=${PYTHON_LIBDIR}
.endif

.if defined(WANT_SWIG_RUBY)
CATEGORIES+=		ruby
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
CONFIGURE_ARGS+=	--with-ruby
.else
CONFIGURE_ARGS+=	--without-ruby
.endif

.if defined(WANT_SWIG_TCL)
CATEGORIES+=		tcl84
BUILD_DEPENDS+=		${LOCALBASE}/bin/tclsh8.4:${PORTSDIR}/lang/tcl84
CONFIGURE_ARGS+=	--with-tclincl=${LOCALBASE}/include/tcl8.4/ \
			--with-tcllib=${LOCALBASE}/lib/tcl8.4/
.endif

.if defined(WANT_SWIG_CSHARP)
BUILD_DEPENDS+=		${LOCALBASE}/bin/mono:${PORTSDIR}/lang/mono
CONFIGURE_ARGS+=	--with-csharp-compiler=${LOCALBASE}/bin/mcs
.else
CONFIGURE_ARGS+=	--without-csharp-compiler
.endif

.if defined(WANT_SWIG_OCAML)
BUILD_DEPENDS+=		${LOCALBASE}/bin/ocamlc:${PORTSDIR}/lang/ocaml
.else
CONFIGURE_ARGS+=	--without-ocaml
.endif

.if defined(WANT_SWIG_ALLEGRCL)
CONFIGURE_ARGS+=	--with-allegrocl
.else
CONFIGURE_ARGS+=	--without-allegrocl
.endif

.if defined(WANT_SWIG_MODULA3)
CONFIGURE_ARGS+=	--with-modula3
.else
CONFIGURE_ARGS+=	--without-modula3
.endif

.if defined(WANT_SWIG_PIKE)
BUILD_DEPENDS+=		${LOCALBASE}/bin/pike:${PORTSDIR}/lang/pike
.else
CONFIGURE_ARGS+=	--without-pike
.endif

.if defined(WANT_SWIG_JAVA)
CATEGORIES+=		java
USE_JAVA=	1.2+
.else
CONFIGURE_ARGS+=	--without-java
.endif

USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LIBTOOL_VER=	13
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC -DPIC"
ALL_TARGET=	swig
PLIST_SUB+=	VER="${VER}"

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's/SKIP_CHICKEN=$$/&"1"/' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|$$RUBY |${RUBY} |' ${WRKSRC}/configure

post-configure:
	${REINPLACE_CMD} -e 's#null#&|| true#' ${WRKSRC}/Makefile

post-install:
	${LN} -f ${PREFIX}/bin/swig ${PREFIX}/bin/swig${VER}

.include <bsd.port.post.mk>
