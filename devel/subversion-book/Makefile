# $FreeBSD$

PORTNAME=	subversion-book
DISTVERSION=	4515
CATEGORIES=	devel misc
MASTER_SITES=	LOCAL/lev
DISTFILES=	# empty
DIST_SUBDIR=	subversion18
EXTRACT_ONLY=	# empty

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Subversion Documentation HTML/PDF

# Creative Commons Legal Code
# http://svnbook.red-bean.com/en/1.7/svn.copyright.html
LICENSE=	CDDL

USES=	tar:bzip2
NO_BUILD=	yes

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		DOCS HTML_SINGLE PDF
OPTIONS_DEFAULT=	HTML_SINGLE

HTML_SINGLE_DESC=	Single HTML page edition
PDF_DESC=		PDF edition

HTML_SINGLE_IMPLIES=	DOCS
PDF_IMPLIES=		DOCS
HTML_SINGLE_DISTFILES=	svn-book-html-r${DISTVERSION}.tar.bz2
PDF_DISTFILES=		svn-book-r${DISTVERSION}.pdf

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDOCS}
IGNORE=	it does not make sense to install dedicated documentation if DOCS are globally disabled
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

do-install-HTML_SINGLE-on:
	${TAR} -xof ${DISTDIR}/${DIST_SUBDIR}/${HTML_SINGLE_DISTFILES} \
		-C ${STAGEDIR}${DOCSDIR}
	(cd ${STAGEDIR}${DOCSDIR}/svn-book-html && ${LN} -s svn-book.html index.html)

do-install-PDF-on:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${PDF_DISTFILES} \
		${STAGEDIR}${DOCSDIR}/svn-book.pdf

.include <bsd.port.mk>
