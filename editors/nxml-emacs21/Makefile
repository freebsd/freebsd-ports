# New ports collection makefile for:	nxml for emacs
# Date created:		26 Oct 2003
# Whom:			Fritz Heinrichmeyer
#
# $FreeBSD$
#

PORTNAME=	nxml-mode
PORTVERSION=	${NXML_VER}
CATEGORIES=	editors elisp
MASTER_SITES=	http://www.thaiopensource.com/download/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A major mode for editing XML documents for emacs21

# distfile version
NXML_VER=	20041004
NXML_STARTUPEL=	nxml-startup.el
EMACS_PORT_NAME=emacs21

INFO=		nxml-mode
DOCUMENTS=	README NEWS VERSION TODO COPYING \
		nxml-mode.xml nxml-mode.rnc test.invalid.xml test.valid.xml
NXML_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/nxml

post-build:
	cd ${WRKSRC}; \
		${MAKE} nxml-mode.info

pre-su-install:
	@${MKDIR} ${NXML_LISPDIR}

do-install:
	cd ${INSTALL_WRKSRC}; \
		${INSTALL_DATA} *.el ${NXML_LISPDIR}; \
		${INSTALL_DATA} *.elc ${NXML_LISPDIR}
.for DIR in char-name schema
	cd ${INSTALL_WRKSRC}; \
		${FIND} ${DIR} -type d -exec ${MKDIR} ${NXML_LISPDIR}/\{} \; ;\
		${FIND} ${DIR} -type f -exec ${INSTALL_DATA} \{} ${NXML_LISPDIR}/\{} \;
.endfor

post-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/nxml-mode.info ${PREFIX}/info
	install-info ${PREFIX}/info/nxml-mode.info ${PREFIX}/info/dir
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for F in ${DOCUMENTS}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${F} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
