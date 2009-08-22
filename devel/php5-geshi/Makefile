# New ports collection makefile for:	php5-geshi
# Date created:				2009-03-18
# Whom:					Eygene Ryabinkin <rea-fbsd@codelabs.ru>
#
# $FreeBSD$
#

PORTNAME=	geshi
PORTVERSION=	1.0.8.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/GeSHi%20${PORTVERSION}
PKGNAMEPREFIX=	php5-
DISTNAME=	GeSHi-${PORTVERSION}

MAINTAINER=	rea-fbsd@codelabs.ru
COMMENT=	Native PHP syntax highlighting engine

WRKSRC=		${WRKDIR}/geshi
PLIST=		${WRKDIR}/PLIST

USE_BZIP2=	yes
USE_PHP=	yes
DEFAULT_PHP_VER=	5
IGNORE_WITH_PHP=	4
NO_BUILD=	yes

PHP_DESTDIR=	lib/php/geshi
DIRS=		\
		geshi
FILES=		\
		geshi.php \
		geshi/abap.php \
		geshi/actionscript.php \
		geshi/actionscript3.php \
		geshi/ada.php \
		geshi/apache.php \
		geshi/applescript.php \
		geshi/apt_sources.php \
		geshi/asm.php \
		geshi/asp.php \
		geshi/autoit.php \
		geshi/avisynth.php \
		geshi/bash.php \
		geshi/basic4gl.php \
		geshi/bf.php \
		geshi/blitzbasic.php \
		geshi/bnf.php \
		geshi/boo.php \
		geshi/c.php \
		geshi/caddcl.php \
		geshi/cadlisp.php \
		geshi/cfdg.php \
		geshi/cfm.php \
		geshi/cil.php \
		geshi/cobol.php \
		geshi/cpp-qt.php \
		geshi/cpp.php \
		geshi/csharp.php \
		geshi/css.php \
		geshi/c_mac.php \
		geshi/d.php \
		geshi/delphi.php \
		geshi/diff.php \
		geshi/div.php \
		geshi/dos.php \
		geshi/dot.php \
		geshi/eiffel.php \
		geshi/email.php \
		geshi/fortran.php \
		geshi/freebasic.php \
		geshi/genero.php \
		geshi/gettext.php \
		geshi/glsl.php \
		geshi/gml.php \
		geshi/gnuplot.php \
		geshi/groovy.php \
		geshi/haskell.php \
		geshi/hq9plus.php \
		geshi/html4strict.php \
		geshi/idl.php \
		geshi/ini.php \
		geshi/inno.php \
		geshi/intercal.php \
		geshi/io.php \
		geshi/java.php \
		geshi/java5.php \
		geshi/javascript.php \
		geshi/kixtart.php \
		geshi/klonec.php \
		geshi/klonecpp.php \
		geshi/latex.php \
		geshi/lisp.php \
		geshi/lolcode.php \
		geshi/lotusformulas.php \
		geshi/lotusscript.php \
		geshi/lscript.php \
		geshi/lua.php \
		geshi/m68k.php \
		geshi/make.php \
		geshi/matlab.php \
		geshi/mirc.php \
		geshi/mpasm.php \
		geshi/mxml.php \
		geshi/mysql.php \
		geshi/nsis.php \
		geshi/objc.php \
		geshi/per.php \
		geshi/ocaml-brief.php \
		geshi/ocaml.php \
		geshi/oobas.php \
		geshi/oracle11.php \
		geshi/oracle8.php \
		geshi/pascal.php \
		geshi/perl.php \
		geshi/php-brief.php \
		geshi/php.php \
		geshi/pic16.php \
		geshi/pixelbender.php \
		geshi/plsql.php \
		geshi/povray.php \
		geshi/powershell.php \
		geshi/robots.php \
		geshi/ruby.php \
		geshi/sas.php \
		geshi/sql.php \
		geshi/scala.php \
		geshi/scheme.php \
		geshi/scilab.php \
		geshi/sdlbasic.php \
		geshi/smalltalk.php \
		geshi/smarty.php \
		geshi/tcl.php \
		geshi/teraterm.php \
		geshi/text.php \
		geshi/thinbasic.php \
		geshi/tsql.php \
		geshi/typoscript.php \
		geshi/vb.php \
		geshi/vbnet.php \
		geshi/verilog.php \
		geshi/vhdl.php \
		geshi/vim.php \
		geshi/visualfoxpro.php \
		geshi/visualprolog.php \
		geshi/whitespace.php \
		geshi/winbatch.php \
		geshi/xml.php \
		geshi/xorg_conf.php \
		geshi/xpp.php \
		geshi/z80.php

DOCDIRS=	\
		api/geshi/core/ \
		api/geshi/ \
		api/media/images/ \
		api/media/ \
		api/__filesource/ \
		api/

DOCFILES=	\
		api/blank.html \
		api/classtrees_geshi.html \
		api/elementindex.html \
		api/elementindex_geshi.html \
		api/errors.html \
		api/geshi/core/GeSHi.html \
		api/geshi/core/_geshi.php.html \
		api/index.html \
		api/li_geshi.html \
		api/media/banner.css \
		api/media/images/AbstractClass.png \
		api/media/images/AbstractClass_logo.png \
		api/media/images/AbstractMethod.png \
		api/media/images/AbstractPrivateClass.png \
		api/media/images/AbstractPrivateClass_logo.png \
		api/media/images/AbstractPrivateMethod.png \
		api/media/images/blank.png \
		api/media/images/Class.png \
		api/media/images/class_folder.png \
		api/media/images/Class_logo.png \
		api/media/images/Constant.png \
		api/media/images/Constructor.png \
		api/media/images/Destructor.png \
		api/media/images/empty.png \
		api/media/images/file.png \
		api/media/images/folder.png \
		api/media/images/Function.png \
		api/media/images/function_folder.png \
		api/media/images/Global.png \
		api/media/images/I.png \
		api/media/images/Index.png \
		api/media/images/Interface.png \
		api/media/images/Interface_logo.png \
		api/media/images/L.png \
		api/media/images/Lminus.png \
		api/media/images/Lplus.png \
		api/media/images/Method.png \
		api/media/images/next_button.png \
		api/media/images/next_button_disabled.png \
		api/media/images/package.png \
		api/media/images/package_folder.png \
		api/media/images/Page.png \
		api/media/images/Page_logo.png \
		api/media/images/previous_button.png \
		api/media/images/previous_button_disabled.png \
		api/media/images/PrivateClass.png \
		api/media/images/PrivateClass_logo.png \
		api/media/images/PrivateMethod.png \
		api/media/images/T.png \
		api/media/images/PrivateVariable.png \
		api/media/images/private_class_logo.png \
		api/media/images/StaticMethod.png \
		api/media/images/StaticVariable.png \
		api/media/images/Tminus.png \
		api/media/images/Tplus.png \
		api/media/images/tutorial.png \
		api/media/images/tutorial_folder.png \
		api/media/images/up_button.png \
		api/media/images/Variable.png \
		api/media/stylesheet.css \
		api/packages.html \
		api/todolist.html \
		api/__filesource/fsource_geshi_core_geshi.php.html \
		BUGS \
		CHANGES \
		COPYING \
		geshi-doc.html \
		geshi-doc.txt \
		phpdoc.ini \
		README \
		THANKS \
		TODO

EXAMPLESFILES=	\
		aliased.php \
		cssgen.php \
		cssgen2.php \
		example.php \
		langcheck.php

post-extract:
# Generate packing list
.for f in ${FILES}
	@${ECHO} '${PHP_DESTDIR}/${f}' >> "${PLIST}"
.endfor
.for d in ${DIRS}
	@${ECHO} '@dirrm ${PHP_DESTDIR}/${d}' >> "${PLIST}"
.endfor
	@${ECHO} '@dirrm ${PHP_DESTDIR}' >> "${PLIST}"
.if !defined(NOPORTDOCS)
.for f in ${DOCFILES}
	@${ECHO} '${DOCSDIR_REL}/${f}' >> "${PLIST}"
.endfor
.for d in ${DOCDIRS}
	@${ECHO} '@dirrm ${DOCSDIR_REL}/${d}' >> "${PLIST}"
.endfor
	@${ECHO} '@dirrm ${DOCSDIR_REL}' >> "${PLIST}"
.endif # !defined(NOPORTDOCS)
.if !defined(NOPORTEXAMPLES)
.for f in ${EXAMPLESFILES}
	@${ECHO} '${EXAMPLESDIR_REL}/${f}' >> "${PLIST}"
.endfor
.for d in ${EXAMPLESDIRS}
	@${ECHO} '@dirrm ${EXAMPLESDIR_REL}/${d}' >> "${PLIST}"
.endfor
	@${ECHO} '@dirrm ${EXAMPLESDIR_REL}' >> "${PLIST}"
.endif # !defined(NOPORTEXAMPLES)

do-install:
.for d in ${DIRS}
	${MKDIR} ${PREFIX}/${PHP_DESTDIR}/${d}
.endfor
.for f in ${FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${PHP_DESTDIR}/${f:H}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for d in ${DOCDIRS}
	${MKDIR} ${DOCSDIR}/${d}
.endfor
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}/${f:H}
.endfor
.endif # !defined(NOPORTDOCS)
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for d in ${EXAMPLESDIRS}
	${MKDIR} ${EXAMPLESDIR}/${d}
.endfor
.for f in ${EXAMPLESFILES}
	${INSTALL_DATA} ${WRKSRC}/contrib/${f} ${EXAMPLESDIR}/${f:H}
.endfor
.endif # !defined(NOPORTEXAMPLES)

.include <bsd.port.mk>
