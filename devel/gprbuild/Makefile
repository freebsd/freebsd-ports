PORTNAME=	gprbuild
DISTVERSIONPREFIX=	v
DISTVERSION=	24.0.0	# Upgrade with devel/libgpr + textproc/xmlada
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adacore multi-language software build tool
WWW=		https://www.adacore.com/gems/gem-65

LICENSE=	GPLv3+ GPLv3RLE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING3

USES=		ada:12,run gmake
USE_BINUTILS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_PROJECT=	gprconfig_kb:kb xmlada:xa

BOOTPATH=	${WRKSRC}/bootstrap/bin
MAKE_JOBS_NUMBER_LIMIT=	4
MAKE_ARGS=	PROCESSORS=${MAKE_JOBS_NUMBER}	\
		ENABLE_SHARED=yes
XMLADA_SRC=	${WRKDIR}/xmlada-${PORTVERSION}
PLATFORM=	${OPSYS:tl}${OSREL}
GARCH=		${ARCH:S/amd64/x86_64/}
CONFIGURE_TARGET=	${GARCH}-portbld-${PLATFORM}
MAKE_ENV+=	GPR_PROJECT_PATH=${WRKSRC}/bootstrap/share/gpr
ALL_TARGET=	all	# libgpr.build.static
INSTALL_TARGET=	install	# libgpr.install
P2STRIP=	libexec/gprbuild/gprbind libexec/gprbuild/gprlib bin/gprname	\
		bin/gprslave bin/gprbuild bin/gprconfig bin/gprls bin/gprinstall\
		bin/gprclean

GCC_VER=	12
PLIST_SUB=	GCC_VER=${GCC_VER}

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCSDIR=	${PREFIX}/gnat${GCC_VER}/share/doc/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/gnat${GCC_VER}/share/examples/${PORTNAME}
PORTDOCS=	*
PORTEXAMPLES=	*
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

pre-configure:
	${REINPLACE_CMD} -e '/^LIB_INSTALLER/s|prefix=|prefix=${STAGEDIR}|'	\
		${WRKSRC}/${MAKEFILE}
	@${ECHO} "*** Build the boostrap script"
	(cd ${WRKSRC} &&	\
	${SETENV} ${CONFIGURE_ENV} ./bootstrap.sh	\
		--with-xmlada=${XMLADA_SRC}	\
		--with-kb=${WRKDIR}/gprconfig_kb-${PORTVERSION}	\
		--prefix=./bootstrap )

do-configure:
	@${ECHO} "*** Make setup"
	(cd ${WRKSRC} &&	\
	${DO_MAKE_BUILD} setup )
	@${ECHO} "*** Register our Ada compiler gnat${GCC_VER}"
	(cd ${WRKSRC} &&	\
	${SETENV} PATH=${PATH}:${LOCALBASE}/gnat${GCC_VER}/bin	\
	./gprconfig --batch --target=${CONFIGURE_TARGET}	\
	--config=Ada,,default,${LOCALBASE}/gnat${GCC_VER}/bin,GNAT )

pre-build:
	@${ECHO} "*** Bootstrap xmlada (configure)"
	(cd ${XMLADA_SRC} &&	\
	${SETENV} ${CONFIGURE_ENV} ./configure --prefix=${WRKSRC}/bootstrap )
	@${ECHO} "*** Bootstrap xmlada (build)"
	(cd ${XMLADA_SRC} &&	\
	${DO_MAKE_BUILD:C|PATH=|PATH=${WRKSRC}/bootstrap/bin:|} all )
	@${ECHO} "*** Bootstrap xmlada (install)"
	(cd ${XMLADA_SRC} &&	\
	${DO_MAKE_BUILD:C|PATH=|PATH=${WRKSRC}/bootstrap/bin:|} install )

do-build:
	@${ECHO} "*** Final build of gprbuild"
	(cd ${WRKSRC} &&	\
	${DO_MAKE_BUILD:C|PATH=|PATH=${WRKSRC}/bootstrap/bin:|} ${ALL_TARGET} )

do-build-DOCS-on:
	@${ECHO} "*** Build docs"
	(cd ${WRKSRC}/doc &&	\
	${DO_MAKE_BUILD} html )

do-build-EXAMPLES-on:
	@${ECHO} "*** Build examples"
	# Fortran is not yet supported on FreeBSD
.for d in ada_f77 matrix
	${MV} ${WRKSRC}/examples/${d} ${WRKDIR}
.endfor
	(cd ${WRKSRC}/examples &&	\
	${DO_MAKE_BUILD:C|PATH=|PATH=${WRKSRC}/bootstrap/bin:|} ${ALL_TARGET} )
.for d in ada_f77 matrix
	${MV} ${WRKDIR}/${d} ${WRKSRC}/examples/
.endfor

do-install:
	@${ECHO} "*** Installation of gprbuild"
	(cd ${WRKSRC} &&	\
	${SETENV} ${MAKE_ENV:C|PATH=|PATH=${WRKSRC}/bootstrap/bin:|} ${FAKEROOT}	\
	${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET} )
.for p in ${P2STRIP}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/gnat${GCC_VER}/${p}
.endfor

.include <bsd.port.mk>
