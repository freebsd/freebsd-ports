# $FreeBSD$

PORTNAME=	subversion-book
DISTVERSION=	4515
CATEGORIES=	devel misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lev
DISTFILES=	svn-book-html-r${DISTVERSION}.tar.bz2 \
		svn-book-r${DISTVERSION}.pdf
DIST_SUBDIR=	subversion18
EXTRACT_ONLY=	svn-book-html-r${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Subversion Documentation HTML/PDF

# Creative Commons Legal Code
# http://svnbook.red-bean.com/en/1.7/svn.copyright.html
LICENSE=	CDDL

USE_BZIP2=	yes
NO_BUILD=	yes

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		HTML_SINGLE PDF
OPTIONS_DEFAULT=	HTML_SINGLE

HTML_SINGLE_DESC=	Single HTML page edition
PDF_DESC=		PDF edition

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDOCS}
IGNORE=	it does not make sense to install dedicated documentation if DOCS are globally disabled
.endif

do-extract:
	@${MKDIR} ${WRKDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

.if ${PORT_OPTIONS:MHTML_SINGLE}
	${TAR} -xof ${DISTDIR}/${DIST_SUBDIR}/svn-book-html-r${PORTVERSION}.tar.bz2 \
		-C ${STAGEDIR}${DOCSDIR}
	(cd ${STAGEDIR}${DOCSDIR}/svn-book-html && ${LN} -s svn-book.html index.html)
.endif

.if ${PORT_OPTIONS:MPDF}
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/svn-book-r${PORTVERSION}.pdf \
		${STAGEDIR}${DOCSDIR}/svn-book.pdf
.endif

.include <bsd.port.mk>
