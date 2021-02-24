# $FreeBSD$

PORTNAME=	newt
PORTVERSION=	0.52.20
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://releases.pagure.org/newt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Not Eriks Windowing Toolkit: console I/O handling library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libslang.so:devel/libslang2 \
		libpopt.so:devel/popt

USES=		autoreconf gmake localbase ncurses pathfix
GNU_CONFIGURE=	yes
MAKE_ENV=	PCFLAGS="${CFLAGS}"
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lncurses

PLIST_SUB=	SOVERSION="${SOVERSION}" \
		VERSION="${PORTVERSION}"

SUB_FILES=	pkgIndex.tcl
SUB_LIST=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=		NLS PYTHON TCL
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
PYTHON_USES=		python
PYTHON_CONFIGURE_WITH=	python
TCL_USES=		tcl
TCL_CONFIGURE_ENV=	ac_cv_c_tclconfig=${TCL_LIBDIR:Q}
TCL_CONFIGURE_WITH=	tcl
TCL_CPPFLAGS=		-I${TCL_INCLUDEDIR:Q}

SOVERSION=	${PORTVERSION:R:E}

post-patch:
	@${REINPLACE_CMD} -e 's|-DUSE_INTERP_RESULT||' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		's|@CPP@|@CC@ -E| ; \
		 s|-D_GNU_SOURCE|| ; \
		 s| -g | |g ; \
		 /make -C/s|^|#| ; \
		 /whiptcl.$$(SOEXT)/s|install|${TRUE}|' ${WRKSRC}/Makefile.in

post-patch-PYTHON-on:
	@${REINPLACE_CMD} -e \
		'/PYTHONVERS/s|=.*|=${PYTHON_VERSION}|' ${WRKSRC}/configure.ac

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/whiptail
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnewt.so

post-install-NLS-on:
	@(cd ${WRKSRC}/po && ${DO_MAKE_BUILD} ${MAKE_ARGS} \
		datadir=${STAGEDIR}${PREFIX}/share ${INSTALL_TARGET})

post-install-PYTHON-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_snack.so

post-install-TCL-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/whip${PORTVERSION}
	(cd ${WRKSRC} && ${INSTALL_LIB} whiptcl.so \
		${STAGEDIR}${PREFIX}/lib/whip${PORTVERSION})
	(cd ${WRKDIR} && ${INSTALL_DATA} pkgIndex.tcl \
		${STAGEDIR}${PREFIX}/lib/whip${PORTVERSION})

.include <bsd.port.mk>
