# ex:ts=8
# New ports collection makefile for:	pccts
# Date created:				22 June 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		pccts
PORTVERSION=		1.33.33
CATEGORIES=		devel
MASTER_SITES=		http://www.polhode.com/
DISTNAME=		pccts${PORTVERSION:R:S/.//}mr${PORTVERSION:E}

MAINTAINER=		neuhauser@chello.cz
COMMENT=	The Purdue Compiler Construction Tool Set

CONFLICTS=	antlr*

USE_ZIP=		yes
WRKSRC=			${WRKDIR}/pccts
ALL_TARGET=
MAKEFILE=		makefile
MAKE_ENV=		COPT="${CFLAGS}"
USE_REINPLACE=		yes

MAN1=			antlr.1 dlg.1

post-patch:
	@${FIND} ${WRKSRC} -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		's|<varargs.h>|<stdarg.h>|g'

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bin/antlr ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bin/dlg ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bin/genmk ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bin/sor ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/antlr/antlr.1 ${PREFIX}/man/man1
	@ ${INSTALL_MAN} ${WRKSRC}/dlg/dlg.1 ${PREFIX}/man/man1
	@ ${MKDIR} ${PREFIX}/include/pccts
.for file in ast charptr
	@ ${INSTALL_DATA} ${WRKSRC}/h/${file}.c ${PREFIX}/include/pccts/${file}.c
.endfor
.for file in AParser ASTBase ATokenBuffer BufFileInput DLexerBase PCCTSAST slist
	@ ${INSTALL_DATA} ${WRKSRC}/h/${file}.cpp ${PREFIX}/include/pccts/${file}.cpp
.endfor
.for file in AParser ASTBase ATokPtr ATokPtrImpl AToken ATokenBuffer ATokenStream BufFileInput DLG_stream_input DLexer DLexerBase PBlackBox PCCTSAST SList antlr ast charbuf charptr config dlgauto dlgdef err int pccts_assert pccts_iostream pccts_istream pccts_setjmp pccts_stdarg pccts_stdio pccts_stdlib pccts_string pcctscfg
	@ ${INSTALL_DATA} ${WRKSRC}/h/${file}.h ${PREFIX}/include/pccts/${file}.h
.endfor
	@ ${MKDIR} ${PREFIX}/share/examples/pccts
.for dir in 1 2 3 4 5 6 7 8 9 10 11 12 13
	@ ${MKDIR} ${PREFIX}/share/examples/pccts/${dir}
.endfor
.for file in makefile 1/makefile 1/test.g 2/MyLexer.cpp 2/MyLexer.h 2/makefile 2/test.g 3/MyLexer.cpp 3/MyLexer.h 3/makefile 3/mytokens.h 3/test.g 4/makefile 4/mytokens.h 4/test.g 5/input.h 5/makefile 5/test.g 6/file1 6/file2 6/main.cpp 6/makefile 6/makefile2 6/test.g 6/test2.g 7/makefile 7/test.g 8/main.cpp 8/makefile 8/test.g 9/makefile 9/test.g 10/makefile 10/test.g 11/input.h 11/makefile 11/test.g 12/makefile 12/test.g 13/makefile 13/test.g
	@ ${INSTALL_DATA} ${WRKSRC}/testcpp/${file} ${PREFIX}/share/examples/pccts/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/pccts
.for file in CHANGES_FROM_131.txt CHANGES_FROM_133.txt CHANGES_FROM_133_BEFORE_MR13.txt KNOWN_PROBLEMS.txt README RIGHTS history.ps history.txt
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/pccts/${file}
.endfor
.endif

.include <bsd.port.mk>
