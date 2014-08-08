# Created by: jhanna@home.com
# $FreeBSD$

PORTNAME=	spin
PORTVERSION=	6.3.2
CATEGORIES=	devel
MASTER_SITES=	http://spinroot.com/spin/Src/
DISTNAME=	spin${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	On-the-fly verification system for asynchronous concurrent systems

OPTIONS_DEFINE=	ISPIN DOCS
OPTIONS_DEFAULT=	ISPIN
ISPIN_DESC=	Install xspin and TCL/Tk dependency

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MISPIN}
USES= 		shebangfix tk
SHEBANG_FILES=	../iSpin/ispin.tcl
tk_OLD_CMD=	/bin/sh
tk_CMD= 	${WISH} -f
PLIST_SUB+=	ISPIN=""
.else
PLIST_SUB+=	ISPIN="@comment "
.endif

DIST_SUBDIR=	spin
WRKSRC=		${WRKDIR}/Spin/Src${PORTVERSION}
MAKEFILE=	makefile
ALL_TARGET=	spin
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DNXT"

post-patch:
	${REINPLACE_CMD} -e "s|exec wish|#exec wish|" ${WRKDIR}/Spin/iSpin/ispin.tcl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spin ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/../iSpin/ispin.tcl ${STAGEDIR}${PREFIX}/bin/ispin
	${MKDIR} ${STAGEDIR}${DOCSDIR}/Doc
	${MKDIR} ${STAGEDIR}${DOCSDIR}/Examples
	${MKDIR} ${STAGEDIR}${DOCSDIR}/Examples/Book_1991
	${MKDIR} ${STAGEDIR}${DOCSDIR}/Examples/Exercises
	${MKDIR} ${STAGEDIR}${DOCSDIR}/Examples/LTL
	${INSTALL_DATA} ${WRKDIR}/Spin/Doc/* ${STAGEDIR}${DOCSDIR}/Doc
	(cd ${WRKDIR}/Spin/Examples && ${FIND} . -type f | ${CPIO} -pdm ${STAGEDIR}${DOCSDIR}/Examples)
	(cd ${WRKDIR}/Spin/Examples/Book_1991 && ${FIND} . -type f | ${CPIO} -pdm ${STAGEDIR}${DOCSDIR}/Examples/Book_1991)
	(cd ${WRKDIR}/Spin/Examples/Exercises && ${FIND} . -type f | ${CPIO} -pdm ${STAGEDIR}${DOCSDIR}/Examples/Exercises)
	(cd ${WRKDIR}/Spin/Examples/LTL && ${FIND} . -type f | ${CPIO} -pdm ${STAGEDIR}${DOCSDIR}/Examples/LTL)
	${INSTALL_MAN} ${WRKDIR}/Spin/Man/spin.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
