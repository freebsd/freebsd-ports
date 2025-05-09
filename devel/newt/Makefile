PORTNAME=	newt
DISTVERSION=	0.52.25
CATEGORIES=	devel
MASTER_SITES=	https://releases.pagure.org/newt/

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Not Eriks Windowing Toolkit: console I/O handling library
WWW=		https://pagure.io/newt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt \
		libslang.so:devel/libslang2

USES=		autoreconf gmake localbase:ldflags ncurses pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_ENV=	PCFLAGS="${CFLAGS}"

SUB_FILES=	pkgIndex.tcl
SUB_LIST=	VERSION="${DISTVERSION}"

PLIST_SUB=	SOVERSION="${DISTVERSION:R:E}" \
		VERSION="${DISTVERSION}"

OPTIONS_DEFINE=		NLS PYTHON TCL
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
PYTHON_USES=		gettext-runtime python
PYTHON_CONFIGURE_WITH=	python=${PYTHON_VERSION}
PYTHON_VARS=		BINARY_ALIAS=python3=${PYTHON_VERSION}
TCL_USES=		tcl
TCL_CONFIGURE_WITH=	tcl
TCL_CONFIGURE_ENV=	ac_cv_c_tclconfig=${TCL_LIBDIR:Q}
TCL_CPPFLAGS=		-I${TCL_INCLUDEDIR:Q} -DUSE_INTERP_RESULT

post-patch:
	@${REINPLACE_CMD} -e \
		's|@CPP@|@CC@ -E| ; \
		 s|-D_GNU_SOURCE|| ; \
		 s| -g | |g ; \
		 /make -C/s|^|#| ; \
		 /whiptcl.$$(SOEXT)/s|install|${TRUE}|' ${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/whiptail
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnewt.so

post-install-NLS-on:
	@(cd ${WRKSRC}/po && ${DO_MAKE_BUILD} ${MAKE_ARGS} \
		datadir=${STAGEDIR}${PREFIX}/share ${INSTALL_TARGET})

post-install-PYTHON-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_snack.so

post-install-TCL-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/whip${DISTVERSION}
	(cd ${WRKSRC} && ${INSTALL_LIB} whiptcl.so \
		${STAGEDIR}${PREFIX}/lib/whip${DISTVERSION})
	(cd ${WRKDIR} && ${INSTALL_DATA} pkgIndex.tcl \
		${STAGEDIR}${PREFIX}/lib/whip${DISTVERSION})
	@${RM} ${STAGEDIR}${PREFIX}/lib/whiptcl.so

.include <bsd.port.mk>
