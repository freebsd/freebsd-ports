# New ports collection makefile for:	cvsbook
# Date created:		2002/02/28
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cvsbook
PORTVERSION=	1.21
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://cvsbook.red-bean.com/
DISTNAME=	${PORTNAME}-${PORTVERSION}-all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tutorial and reference for CVS

OPTIONS=	CVSBOOK_INFO		"Install the info version" on \
		CVSBOOK_SINGLE_HTML	"Install the single-html version" on \
		CVSBOOK_SPLIT_HTML	"Install the split-html version" off \
		CVSBOOK_POSTSCRIPT	"Install the postscript version" on \
		CVSBOOK_PDF		"Install the PDF version" on

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if defined(WITH_CVSBOOK_SPLIT_HTML)
ALL_TARGET=	html-distributed
.else
NO_BUILD=	yes
.endif

.if !defined(WITHOUT_CVSBOOK_INFO)
INFO=		cvsbook
INFODIR=	${PREFIX}/${INFO_PATH}
INSTALL_INFO?=	install-info
.endif
.if !defined(WITHOUT_CVSBOOK_SINGLE_HTML)
PLIST_FILES+=	%%DOCSDIR%%/cvsbook.html
WANT_DOCSDIR=	yes
.endif
.if !defined(WITHOUT_CVSBOOK_POSTSCRIPT)
PLIST_FILES+=	%%DOCSDIR%%/cvsbook.ps
WANT_DOCSDIR=	yes
.endif
.if !defined(WITHOUT_CVSBOOK_PDF)
PLIST_FILES+=	%%DOCSDIR%%/cvsbook.pdf
WANT_DOCSDIR=	yes
.endif
.if defined(WITH_CVSBOOK_SPLIT_HTML)
PLIST_DIRS+=	%%DOCSDIR%%/cvsbook-shtml
WANT_DOCSDIR=	yes
.endif
.if defined(WANT_DOCSDIR)
PLIST_DIRS+=	%%DOCSDIR%%
.endif

.if defined(WITH_CVSBOOK_SPLIT_HTML)
post-patch:
	${REINPLACE_CMD} -e \
	'/Non-monolithic HTML not supported/s|@.*|makeinfo --html main.texi|' \
		${WRKSRC}/Makefile
.endif

.if defined(WITH_CVSBOOK_SPLIT_HTML)
pre-install:
PLIST_FILES+=	`cd ${WRKSRC}/cvsbook && ${FIND} . -type f| ${CUT} -c2- \
	| ${SED} 's|^|${DOCSDIR:S,${PREFIX}/,,}/cvsbook-shtml|' \
	| ${SORT}`
.endif

do-install:
.if defined(WANT_DOCSDIR)
	@${MKDIR} ${DOCSDIR}
.endif
.if defined(WITH_CVSBOOK_SPLIT_HTML)
	@${MKDIR} ${DOCSDIR}/cvsbook-shtml
	@cd ${WRKSRC}/cvsbook && ${INSTALL_DATA} -- *.html ${DOCSDIR}/cvsbook-shtml
.endif
.if !defined(WITHOUT_CVSBOOK_SINGLE_HTML)
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.html ${DOCSDIR}
.endif
.if !defined(WITHOUT_CVSBOOK_PDF)
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.pdf ${DOCSDIR}
.endif
.if !defined(WITHOUT_CVSBOOK_POSTSCRIPT)
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.ps ${DOCSDIR}
.endif
.if !defined(WITHOUT_CVSBOOK_INFO)
	@${INSTALL_DATA} ${WRKSRC}/cvsbook.info* ${INFODIR}
	@${INSTALL_INFO} ${INFODIR}/cvsbook.info ${INFODIR}/dir
.endif

.include <bsd.port.post.mk>
