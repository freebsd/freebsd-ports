PORTNAME=	g-golf
DISTVERSION=	0.8.0-a.5
CATEGORIES=	devel
MASTER_SITES=	GNU
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	andrew@tao11.riddles.org.uk
COMMENT=	Guile Object Library for GNOME
WWW=		https://www.gnu.org/software/g-golf/index.html

LICENSE=	LGPL3+

BUILD_DEPENDS+=	guile-lib-${GUILE_FLAVOR}>=0.2.5:devel/guile-lib@${GUILE_FLAVOR}
RUN_DEPENDS+=	guile-lib-${GUILE_FLAVOR}>=0.2.5:devel/guile-lib@${GUILE_FLAVOR}
LIB_DEPENDS+=	libffi.so:devel/libffi

USES=		gmake gnome guile:2.2,3.0,flavors libtool makeinfo pkgconfig
USE_GNOME=	glib20 introspection:build,run

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-guile-site \
		--libdir='$${prefix}/lib/guile/${GUILE_VER}/extensions'

MAKE_JOBS_UNSAFE=yes
INSTALL_TARGET=	install-strip

INFO=		g-golf
INFO_PATH=	${GUILE_INFO_PATH}

EXAMPLESDIR=	${GUILE_EXAMPLES_DIR}/${PORTNAME}
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-patch-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${FIND} . -type f -name '*.scm' \
	  -exec ${REINPLACE_CMD} '3s/exec guile/exec guile-${GUILE_VER}/' {} \; )

# DO NOT try and add rules here to strip .go files, no matter how loudly
# testport / stage-qa shouts at you about it, because .go files (which are
# compiled bytecode) are not intended to be stripped and doing so causes
# breakage at run time.

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${GUILE_PKGCONFIG_DIR}
	${MV} ${STAGEDIR}${PREFIX}/lib/guile/${GUILE_VER}/extensions/pkgconfig/*.pc \
	      ${STAGEDIR}${PREFIX}/${GUILE_PKGCONFIG_DIR}/
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/guile/${GUILE_VER}/extensions/pkgconfig

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && \
	  ${COPYTREE_BIN} . ${STAGEDIR}${EXAMPLESDIR} \
		  "-name *\.scm" ; \
	  ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} \
		  "! -name \Makefile* ! -name *\.bak ! -name *\.orig ! -name *\.scm" )

.include <bsd.port.mk>
