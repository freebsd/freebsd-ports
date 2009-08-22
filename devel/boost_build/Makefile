# Ports collection makefile for:  boost_build
# Date Created:			  13 February 2008
# Whom:				  Bruce M. Simpson
#
# $FreeBSD$

PORTNAME=	boost_build
PORTVERSION=	2.0.m12
CATEGORIES=	devel
MASTER_SITES=	SF/boost/boost-build/2.0-m12
DISTNAME=	${PORTNAME:S/_/-/g}-${PORTVERSION:S/.m/-m/}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Extensible cross-platform build tool suite

RUN_DEPENDS=	${LOCALBASE}/bin/bjam:${PORTSDIR}/devel/boost-jam

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:S/_/-/g}
NO_BUILD=	defined

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

BOOST_BUILD_DIRS=	\
	util		\
	tools/types	\
	tools		\
	options		\
	kernel		\
	build

BOOST_BUILD_FILES=			\
	boost-build.jam			\
	bootstrap.jam			\
	user-config.jam			\
	site-config.jam			\
	build-system.jam		\
	build/alias.jam			\
	build/build-request.jam		\
	build/feature.jam		\
	build/generators.jam		\
	build/modifiers.jam		\
	build/project.jam		\
	build/property-set.jam		\
	build/property.jam		\
	build/readme.txt		\
	build/scanner.jam		\
	build/targets.jam		\
	build/toolset.jam		\
	build/type.jam			\
	build/version.jam		\
	build/virtual-target.jam	\
	kernel/boost-build.jam		\
	kernel/bootstrap.jam		\
	kernel/class.jam		\
	kernel/errors.jam		\
	kernel/modules.jam		\
	options/help.jam		\
	tools/acc.jam			\
	tools/bison.jam			\
	tools/boostbook-config.jam	\
	tools/boostbook.jam		\
	tools/borland.jam		\
	tools/builtin.jam		\
	tools/cast.jam			\
	tools/common.jam		\
	tools/como-linux.jam		\
	tools/como-win.jam		\
	tools/como.jam			\
	tools/cw-config.jam		\
	tools/cw.jam			\
	tools/darwin.jam		\
	tools/dmc.jam			\
	tools/docutils.jam		\
	tools/doxproc.py		\
	tools/doxygen-config.jam	\
	tools/doxygen.jam		\
	tools/fop.jam			\
	tools/fortran.jam		\
	tools/gcc.jam			\
	tools/generate.jam		\
	tools/gettext.jam		\
	tools/gfortran.jam		\
	tools/hp_cxx.jam		\
	tools/hpfortran.jam		\
	tools/ifort.jam			\
	tools/intel-linux.jam		\
	tools/intel-win.jam		\
	tools/intel.jam			\
	tools/lex.jam			\
	tools/make.jam			\
	tools/mc.jam			\
	tools/midl.jam			\
	tools/mpi.jam			\
	tools/msvc-config.jam		\
	tools/msvc.jam			\
	tools/notfile.jam		\
	tools/package.jam		\
	tools/pch.jam			\
	tools/python-config.jam		\
	tools/python.jam		\
	tools/qcc.jam			\
	tools/qt.jam			\
	tools/qt3.jam			\
	tools/qt4.jam			\
	tools/quickbook-config.jam	\
	tools/quickbook.jam		\
	tools/rc.jam			\
	tools/stage.jam			\
	tools/stlport.jam		\
	tools/sun.jam			\
	tools/symlink.jam		\
	tools/testing.jam		\
	tools/types/asm.jam		\
	tools/types/cpp.jam		\
	tools/types/exe.jam		\
	tools/types/html.jam		\
	tools/types/lib.jam		\
	tools/types/obj.jam		\
	tools/types/qt.jam		\
	tools/types/register.jam	\
	tools/types/rsp.jam		\
	tools/unix.jam			\
	tools/vacpp.jam			\
	tools/whale.jam			\
	tools/xlf.jam			\
	tools/xsltproc-config.jam	\
	tools/xsltproc.jam		\
	util/assert.jam			\
	util/container.jam		\
	util/doc.jam			\
	util/indirect.jam		\
	util/numbers.jam		\
	util/option.jam			\
	util/order.jam			\
	util/os.jam			\
	util/path.jam			\
	util/print.jam			\
	util/regex.jam			\
	util/sequence.jam		\
	util/set.jam			\
	util/string.jam			\
	util/utility.jam

PLIST_DIRS=	${BOOST_BUILD_DIRS:C/^/${DATADIR_REL}\//} \
		${DATADIR_REL}
PLIST_FILES=	${BOOST_BUILD_FILES:C/^/${DATADIR_REL}\//}

.if !defined(NOPORTDOCS)
BOOST_BUILD_DOC_DIRS=		\
	html/bbv2/tutorial	\
	html/bbv2/tasks		\
	html/bbv2/reference	\
	html/bbv2/recipies	\
	html/bbv2/faq		\
	html/bbv2/extending	\
	html/bbv2/builtins	\
	html/bbv2/advanced/differences_to_v1 \
	html/bbv2/advanced/builtins	\
	html/bbv2/advanced	\
	html/bbv2		\
	html/jam		\
	html

BOOST_BUILD_DOC_FILES=		\
	html/jam/usage.html \
	html/jam/miscellaneous.html \
	html/jam/language.html \
	html/jam/history.html \
	html/jam/building.html \
	html/index.html \
	html/bbv2/vs_v1.html \
	html/bbv2/tutorial/testing.html \
	html/bbv2/tutorial/properties.html \
	html/bbv2/tutorial/prebuilt.html \
	html/bbv2/tutorial/linkage.html \
	html/bbv2/tutorial/libs.html \
	html/bbv2/tutorial/hierarchy.html \
	html/bbv2/tutorial/conditions.html \
	html/bbv2/tutorial.html \
	html/bbv2/tasks/libraries.html \
	html/bbv2/tasks/installing.html \
	html/bbv2/tasks/alias.html \
	html/bbv2/tasks.html \
	html/bbv2/reference/tools.html \
	html/bbv2/reference/rules.html \
	html/bbv2/reference/precompiled_headers.html \
	html/bbv2/reference/generators.html \
	html/bbv2/reference/generated_headers.html \
	html/bbv2/reference/definitions.html \
	html/bbv2/reference/buildprocess.html \
	html/bbv2/reference.html \
	html/bbv2/recipies/site-config.html \
	html/bbv2/jam.html \
	html/bbv2/installation.html \
	html/bbv2/howto.html \
	html/bbv2/faq/s08.html \
	html/bbv2/faq/s07.html \
	html/bbv2/faq/s05.html \
	html/bbv2/faq/s04.html \
	html/bbv2/faq/s02.html \
	html/bbv2/faq/header-only-libraries.html \
	html/bbv2/faq/external.html \
	html/bbv2/faq/envar.html \
	html/bbv2/faq/dll-path.html \
	html/bbv2/faq.html \
	html/bbv2/extending/toolset_modules.html \
	html/bbv2/extending/tools.html \
	html/bbv2/extending/targets.html \
	html/bbv2/extending/rules.html \
	html/bbv2/extending/features.html \
	html/bbv2/extender.html \
	html/bbv2/builtins/testing.html \
	html/bbv2/builtins/raw.html \
	html/bbv2/advanced/targets.html \
	html/bbv2/advanced/projects.html \
	html/bbv2/advanced/invocation.html \
	html/bbv2/advanced/differences_to_v1/jamfiles.html \
	html/bbv2/advanced/differences_to_v1/build_process.html \
	html/bbv2/advanced/configuration.html \
	html/bbv2/advanced/builtins/features.html \
	html/bbv2/advanced/build_process.html \
	html/bbv2/advanced.html \
	userman.pdf \
	tools.html \
	development_plan.html

PLIST_DIRS+=	${BOOST_BUILD_DOC_DIRS:C/^/${DOCSDIR_REL}\//} \
		${DOCSDIR_REL}
PLIST_FILES+=	${BOOST_BUILD_DOC_FILES:C/^/${DOCSDIR_REL}\//} \
		share/doc/boost.png
.endif

.if !defined(NOPORTEXAMPLES)
BOOST_BUILD_EXAMPLE_DIRS=		\
	variant/libs			\
	variant				\
	qt/qt4/uic			\
	qt/qt4/moccable-cpp		\
	qt/qt4/hello			\
	qt/qt4				\
	qt/qt3/uic			\
	qt/qt3/moccable-cpp		\
	qt/qt3/hello			\
	qt/qt3				\
	qt				\
	python_modules			\
	pch/source			\
	pch/include			\
	pch				\
	make				\
	libraries/util/foo/include	\
	libraries/util/foo		\
	libraries/util			\
	libraries/app			\
	libraries			\
	hello				\
	gettext				\
	generator			\
	generate			\
	customization

BOOST_BUILD_EXAMPLE_FILES=			\
	variant/readme.txt			\
	variant/project-root.jam		\
	variant/libs/l.cpp			\
	variant/libs/Jamfile			\
	variant/a.cpp				\
	variant/Jamfile				\
	qt/qt4/uic/main.cpp			\
	qt/qt4/uic/hello_world_widget.ui	\
	qt/qt4/uic/Jamroot			\
	qt/qt4/moccable-cpp/main.cpp		\
	qt/qt4/moccable-cpp/Jamroot		\
	qt/qt4/hello/main.cpp			\
	qt/qt4/hello/arrow.h			\
	qt/qt4/hello/arrow.cpp			\
	qt/qt4/hello/Jamroot			\
	qt/qt3/uic/main.cpp			\
	qt/qt3/uic/hello_world_widget.ui	\
	qt/qt3/uic/Jamroot			\
	qt/qt3/moccable-cpp/main.cpp		\
	qt/qt3/moccable-cpp/Jamroot		\
	qt/qt3/hello/main.cpp			\
	qt/qt3/hello/canvas.h			\
	qt/qt3/hello/canvas.cpp			\
	qt/qt3/hello/Jamroot			\
	qt/README.txt				\
	python_modules/readme.txt		\
	python_modules/python_helpers.py	\
	python_modules/python_helpers.jam	\
	python_modules/Jamroot			\
	pch/source/hello_world.cpp		\
	pch/include/pch.hpp			\
	pch/Jamroot				\
	make/readme.txt				\
	make/main_cpp.pro			\
	make/Jamroot				\
	libraries/util/foo/include/lib1.h	\
	libraries/util/foo/bar.cpp		\
	libraries/util/foo/Jamfile		\
	libraries/app/app.cpp			\
	libraries/app/Jamfile			\
	libraries/Jamroot			\
	hello/hello.cpp				\
	hello/Jamroot				\
	gettext/russian.po			\
	gettext/readme.txt			\
	gettext/project-root.jam		\
	gettext/main.cpp			\
	gettext/Jamfile				\
	generator/soap.jam			\
	generator/foo.gci			\
	generator/README.txt			\
	generator/Jamroot			\
	generate/a.cpp				\
	generate/REAME.txt			\
	generate/Jamroot			\
	customization/verbatim.jam		\
	customization/usage.verbatim		\
	customization/t2.verbatim		\
	customization/t1.verbatim		\
	customization/readme.txt		\
	customization/project-root.jam		\
	customization/inline_file.py		\
	customization/codegen.cpp		\
	customization/class.verbatim		\
	customization/Jamfile			\
	boost-build.jam

PLIST_DIRS+=	${BOOST_BUILD_EXAMPLE_DIRS:C/^/${EXAMPLESDIR_REL}\//} \
		${EXAMPLESDIR_REL}
PLIST_FILES+=	${BOOST_BUILD_EXAMPLE_FILES:C/^/${EXAMPLESDIR_REL}\//}
.endif

do-install:
	@${MKDIR} ${DATADIR}
.for _dir in ${BOOST_BUILD_DIRS}
	@${MKDIR} ${DATADIR}/${_dir}
.endfor
.for _file in ${BOOST_BUILD_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${_file} ${DATADIR}/${_file}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for _dir in ${BOOST_BUILD_DOC_DIRS}
	@${MKDIR} ${DOCSDIR}/${_dir}
.endfor
	@${INSTALL_MAN} ${WRKSRC}/boost.png ${PREFIX}/share/doc/boost.png
.for _file in ${BOOST_BUILD_DOC_FILES}
	@${INSTALL_MAN} ${WRKSRC}/doc/${_file} ${DOCSDIR}/${_file}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for _dir in ${BOOST_BUILD_EXAMPLE_DIRS}
	@${MKDIR} ${EXAMPLESDIR}/${_dir}
.endfor
.for _file in ${BOOST_BUILD_EXAMPLE_FILES}
	@${INSTALL_MAN} ${WRKSRC}/example/${_file} ${EXAMPLESDIR}/${_file}
.endfor
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
