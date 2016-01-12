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

LICENSE=	GPLv2+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_ARCH=	yes

OPTIONS_MULTI=		CVSBOOK
OPTIONS_MULTI_CVSBOOK=	INFO SINGLE_HTML SPLIT_HTML POSTSCRIPT PDF
OPTIONS_DEFAULT=	INFO SINGLE_HTML POSTSCRIPT PDF
OPTIONS_SUB=		yes

INFO_DESC=		Install the info version
SINGLE_HTML_DESC=	Install the single HTML version
SPLIT_HTML_DESC=	Install the split HTML version
POSTSCRIPT_DESC=	Install the Postscript version
PDF_DESC=		Install the PDF version

SPLIT_HTML_ALL_TARGET=		html-distributed
SPLIT_HTML_VARS_OFF=		NO_BUILD=yes
INFO_INFO=			cvsbook
INFO_VARS=			INFODIR=${PREFIX}/${INFO_PATH}

post-patch-SPLIT_HTML-on:
	@${REINPLACE_CMD} -e \
	'/Non-monolithic HTML not supported/s|@.*|makeinfo --html main.texi|' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

do-install-SPLIT_HTML-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/cvsbook-shtml
	${INSTALL_DATA} ${WRKSRC}/cvsbook/*.html ${STAGEDIR}${DOCSDIR}/cvsbook-shtml

do-install-SINGLE_HTML-on:
	${INSTALL_DATA} ${WRKSRC}/cvsbook.html ${STAGEDIR}${DOCSDIR}

do-install-PDF-on:
	${INSTALL_DATA} ${WRKSRC}/cvsbook.pdf ${STAGEDIR}${DOCSDIR}

do-install-POSTSCRIPT-on:
	${INSTALL_DATA} ${WRKSRC}/cvsbook.ps ${STAGEDIR}${DOCSDIR}

do-install-INFO-on:
	@${MKDIR} ${STAGEDIR}${INFODIR}
	${INSTALL_DATA} ${WRKSRC}/cvsbook.info* ${STAGEDIR}${INFODIR}

post-install:
	@${RMDIR} ${STAGEDIR}${DOCSDIR} >/dev/null 2>&1 || ${TRUE} # remove if empty
	@if [ -d ${STAGEDIR}${DOCSDIR} ]; then \
		${FIND} ${STAGEDIR}${DOCSDIR} -type f | \
		${SED} 's|^${STAGEDIR}${PREFIX}/||' > ${TMPPLIST}; \
	fi

.include <bsd.port.mk>
