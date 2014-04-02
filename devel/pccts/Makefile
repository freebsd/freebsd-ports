# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	pccts
PORTVERSION=	1.33.33
CATEGORIES=	devel
MASTER_SITES=	http://www.polhode.com/
DISTNAME=	pccts${PORTVERSION:R:S/.//}mr${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Purdue Compiler Construction Tool Set

CONFLICTS=	antlr*

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		zip
MAKE_ENV=	COPT="${CFLAGS}"
MAKEFILE=	makefile
ALL_TARGET=	# empty
CFLAGS+=	-DPCCTS_USE_STDARG

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${FIND} ${WRKSRC}/testcpp -name "makefile*" | ${XARGS} ${REINPLACE_CMD} -E \
		-e '/^CCC/ s,=.*,=$$(CXX),' \
		-e '/^PCCTS/ s,\.\.\/\.\.,$$(PREFIX),' \
		-e '/^(A|ANTLR)_H/ s,h,include/pccts,'

do-install:
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} antlr dlg genmk sor \
		${STAGEDIR}${PREFIX}/bin)
	${INSTALL_MAN} ${WRKSRC}/antlr/antlr.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/dlg/dlg.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/pccts
	(cd ${WRKSRC}/h && ${INSTALL_DATA} *.c *.cpp *.h \
		${STAGEDIR}${PREFIX}/include/pccts)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CHANGES_FROM_131.txt \
		CHANGES_FROM_133.txt CHANGES_FROM_133_BEFORE_MR13.txt \
		KNOWN_PROBLEMS.txt README RIGHTS history.ps history.txt \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/testcpp && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR} "! -name *.bak")

.include <bsd.port.mk>
