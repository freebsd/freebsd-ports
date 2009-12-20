# New ports collection makefile for:	nxml for emacs
# Date created:		26 Oct 2003
# Whom:			Fritz Heinrichmeyer
#
# $FreeBSD$
#

PORTNAME=	nxml-mode
PORTVERSION=	${NXML_VER}
PORTREVISION=	4
CATEGORIES=	editors elisp
MASTER_SITES=	http://www.thaiopensource.com/download/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A major mode for editing XML documents for ${EMACS_PORT_NAME}

USE_EMACS=	yes

INFO=		nxml-mode
PORTDOCS=	README NEWS VERSION TODO COPYING \
		nxml-mode.xml nxml-mode.rnc test.invalid.xml test.valid.xml

NXML_VER=	20041004
NXML_STARTUPEL=	nxml-startup.el
NXML_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/nxml
NXML_INSTDIRS=	. char-name char-name/unicode schema
NXML_INCLEXP=	\.el$$\|\.elc$$\|\.rnc$$\|\.xml$$
NXML_EXCLEXP=	nxml-mode.xml\|nxml-mode.rnc\|test.invalid.xml\|test.valid.xml

do-install:
	@${MKDIR} ${NXML_INSTDIRS:S,^,${NXML_LISPDIR}/,}
.for D in ${NXML_INSTDIRS}
	@cd ${INSTALL_WRKSRC}/${D} && \
		${LS} \
		| ${GREP} '${NXML_INCLEXP}' | ${GREP} -v '${NXML_EXCLEXP}' \
		| ${XARGS} -J % ${INSTALL_DATA} % ${NXML_LISPDIR}/${D}
.endfor

post-install:
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/nxml-mode.info ${PREFIX}/info
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${INSTALL_WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if (${EMACS_PORT_NAME} == "emacs23")
IGNORE=     incorporated into Emacs 23
.endif

.include <bsd.port.post.mk>
