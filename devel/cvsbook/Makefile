# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	cvsbook
PORTVERSION=	1.21
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://cvsbook.red-bean.com/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tutorial and reference for CVS

OPTIONS_MULTI=		CVSBOOK
OPTIONS_MULTI_CVSBOOK=	INFO SINGLE_HTML SPLIT_HTML POSTSCRIPT PDF
INFO_DESC=		Install the info version
SINGLE_HTML_DESC=	Install the single HTML version
SPLIT_HTML_DESC=	Install the split HTML version
POSTSCRIPT_DESC=	Install the Postscript version
PDF_DESC=		Install the PDF version
OPTIONS_DEFAULT=	INFO SINGLE_HTML POSTSCRIPT PDF

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSPLIT_HTML}
ALL_TARGET=	html-distributed
.else
NO_BUILD=	yes
.endif

.if ${PORT_OPTIONS:MINFO}
INFO=		cvsbook
INFODIR=	${PREFIX}/${INFO_PATH}
.endif

.if ${PORT_OPTIONS:MSINGLE_HTML}
PLIST_FILES+=	%%DOCSDIR%%/cvsbook.html
.endif

.if ${PORT_OPTIONS:MPOSTSCRIPT}
PLIST_FILES+=	%%DOCSDIR%%/cvsbook.ps
.endif

.if ${PORT_OPTIONS:MPDF}
PLIST_FILES+=	%%DOCSDIR%%/cvsbook.pdf
.endif

.if ${PORT_OPTIONS:MSPLIT_HTML}
post-patch:
	@${REINPLACE_CMD} -e \
	'/Non-monolithic HTML not supported/s|@.*|makeinfo --html main.texi|' \
		${WRKSRC}/Makefile
.endif

.if ${PORT_OPTIONS:MSPLIT_HTML}
pre-install:
PLIST_FILES+=	`cd ${WRKSRC}/cvsbook && ${FIND} . -type f| ${CUT} -c2- \
	| ${SED} 's|^|${DOCSDIR:S,${PREFIX}/,,}/cvsbook-shtml|' \
	| ${SORT}`
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MSPLIT_HTML}
	@${MKDIR} ${DOCSDIR}/cvsbook-shtml
	@cd ${WRKSRC}/cvsbook && ${INSTALL_DATA} -- *.html ${STAGEDIR}${DOCSDIR}/cvsbook-shtml
.endif
.if ${PORT_OPTIONS:MSINGLE_HTML}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.html ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MPDF}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.pdf ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MPOSTSCRIPT}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.ps ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MINFO}
	@${MKDIR} ${STAGEDIR}${INFODIR}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.info* ${STAGEDIR}${INFODIR}
.endif

.include <bsd.port.mk>
