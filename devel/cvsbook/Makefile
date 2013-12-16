# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	cvsbook
PORTVERSION=	1.21
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://cvsbook.red-bean.com/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tutorial and reference for CVS

OPTIONS_MULTI=		CVSBOOK
OPTIONS_MULTI_CVSBOOK=	INFO SINGLE_HTML SPLIT_HTML POSTSCRIPT PDF
INFO_DESC=		Install the info version
SINGLE_HTML_DESC=	Install the single HTML version
SPLIT_HTML_DESC=	Install the split HTML version
POSTSCRIPT_DESC=	Install the Postscript version
PDF_DESC=		Install the PDF version
OPTIONS_DEFAULT=	INFO SINGLE_HTML POSTSCRIPT PDF

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSPLIT_HTML}
ALL_TARGET=	html-distributed
.else
NO_BUILD=	yes
.endif

.if ${PORT_OPTIONS:MINFO}
INFO=		cvsbook
INFODIR=	${PREFIX}/${INFO_PATH}
INSTALL_INFO?=	install-info
.endif

.if ${PORT_OPTIONS:MSINGLE_HTML}
PLIST_FILES+=	%%DOCSDIR%%/cvsbook.html
WANT_DOCSDIR=	yes
.endif

.if ${PORT_OPTIONS:MPOSTSCRIPT}
PLIST_FILES+=	%%DOCSDIR%%/cvsbook.ps
WANT_DOCSDIR=	yes
.endif

.if ${PORT_OPTIONS:MPDF}
PLIST_FILES+=	%%DOCSDIR%%/cvsbook.pdf
WANT_DOCSDIR=	yes
.endif

.if ${PORT_OPTIONS:MSPLIT_HTML}
PLIST_DIRS+=	%%DOCSDIR%%/cvsbook-shtml
WANT_DOCSDIR=	yes
.endif

.if defined(WANT_DOCSDIR)
PLIST_DIRS+=	%%DOCSDIR%%
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
.if defined(WANT_DOCSDIR)
	@${MKDIR} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MSPLIT_HTML}
	@${MKDIR} ${DOCSDIR}/cvsbook-shtml
	@cd ${WRKSRC}/cvsbook && ${INSTALL_DATA} -- *.html ${DOCSDIR}/cvsbook-shtml
.endif
.if ${PORT_OPTIONS:MSINGLE_HTML}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.html ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MPDF}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.pdf ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MPOSTSCRIPT}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.ps ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MINFO}
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.info* ${INFODIR}
	@${INSTALL_INFO} ${INFODIR}/cvsbook.info ${INFODIR}/dir
.endif

.include <bsd.port.mk>
