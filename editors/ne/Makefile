# Created by: Andrej Zverev <az@inec.ru>
# $FreeBSD$

PORTNAME=	ne
PORTVERSION=	2.5
CATEGORIES=	editors
MASTER_SITES=	http://ne.dsi.unimi.it/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice and powerful editor

LICENSE=	GPLv3

OPTIONS_DEFINE=	DEBUG DOCS

BUILD_WRKSRC=	${WRKSRC}/src

USE_PERL5_BUILD=yes
USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="-lgnuregex" \
		NE_GLOBAL_DIR="${DATADIR}"
MAKE_JOBS_SAFE=	yes

MAN1=		${PORTNAME}.1
INFO=		${PORTNAME}
PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/default.keys %%DATADIR%%/default.menus \
		%%DATADIR%%/syntax/4gl.jsf %%DATADIR%%/syntax/ada.jsf \
		%%DATADIR%%/syntax/asm.jsf %%DATADIR%%/syntax/awk.jsf \
		%%DATADIR%%/syntax/c.jsf %%DATADIR%%/syntax/cobol.jsf \
		%%DATADIR%%/syntax/conf.jsf %%DATADIR%%/syntax/csh.jsf \
		%%DATADIR%%/syntax/css.jsf %%DATADIR%%/syntax/diff.jsf \
		%%DATADIR%%/syntax/fortran.jsf %%DATADIR%%/syntax/haskell.jsf \
		%%DATADIR%%/syntax/html.jsf %%DATADIR%%/syntax/java.jsf \
		%%DATADIR%%/syntax/joerc.jsf %%DATADIR%%/syntax/jsf.jsf \
		%%DATADIR%%/syntax/jsf_check.jsf %%DATADIR%%/syntax/lisp.jsf \
		%%DATADIR%%/syntax/lua.jsf %%DATADIR%%/syntax/m4.jsf \
		%%DATADIR%%/syntax/mail.jsf %%DATADIR%%/syntax/mason.jsf \
		%%DATADIR%%/syntax/matlab.jsf %%DATADIR%%/syntax/ocaml.jsf \
		%%DATADIR%%/syntax/pascal.jsf %%DATADIR%%/syntax/perl.jsf \
		%%DATADIR%%/syntax/php.jsf %%DATADIR%%/syntax/ps.jsf \
		%%DATADIR%%/syntax/python.jsf %%DATADIR%%/syntax/rexx.jsf \
		%%DATADIR%%/syntax/ruby.jsf %%DATADIR%%/syntax/sed.jsf \
		%%DATADIR%%/syntax/sh.jsf %%DATADIR%%/syntax/skill.jsf \
		%%DATADIR%%/syntax/sml.jsf %%DATADIR%%/syntax/spec.jsf \
		%%DATADIR%%/syntax/sql.jsf %%DATADIR%%/syntax/tabs.jsf \
		%%DATADIR%%/syntax/tcl.jsf %%DATADIR%%/syntax/tex.jsf \
		%%DATADIR%%/syntax/texinfo.jsf %%DATADIR%%/syntax/troff.jsf \
		%%DATADIR%%/syntax/txt2tags.jsf %%DATADIR%%/syntax/verilog.jsf \
		%%DATADIR%%/syntax/vhdl.jsf %%DATADIR%%/syntax/xml.jsf
PLIST_DIRS=	%%DATADIR%%/syntax %%DATADIR%%

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDEBUG}
CFLAGS+=	-DNODEBUG
.endif

post-patch:
.for file in actions.c
	@${REINPLACE_CMD} -e 's|tmpnam(|mkstemp(|g' ${BUILD_WRKSRC}/${file}
.endfor
.for file in ne.c search.c
	@${REINPLACE_CMD} -e 's|"regex\.h"|<gnu/regex.h>|g' ${BUILD_WRKSRC}/${file}
.endfor
.for file in makefile
	@${REINPLACE_CMD} -e '/[[:space:]]regex.o/d ; \
		 s|regex.h||g' ${BUILD_WRKSRC}/${file}
.endfor

post-build:
	cd ${WRKSRC}/doc && makeinfo ${PORTNAME}.texinfo

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.info ${PREFIX}/${INFO_PATH}
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA}	${WRKSRC}/doc/default.* ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} syntax ${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.txt ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${DOCSDIR})
.endif

.include <bsd.port.mk>
