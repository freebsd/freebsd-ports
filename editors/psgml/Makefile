PORTNAME=	psgml
PORTVERSION=	1.4.0
PORTREVISION=	26
CATEGORIES=	editors elisp
MASTER_SITES=	SF/${PORTNAME}/ALPHA%20${PORTNAME}/1.3.2
DISTNAME=	${PORTNAME}-1.3.2

PATCH_SITES=	LOCAL/hrs
PATCHFILES=	psgml-symbol-conflict-050503.diff.gz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Major mode for editing SGML and XML documents for Emacs
WWW=		http://www.lysator.liu.se/~lenst/about_psgml/

LICENSE=	GPLv2

USES=		emacs

CONFLICTS_INSTALL=	psgml-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	${PSGML_STARTUP}
SUB_LIST=	PSGML_LISPDIR=${PSGML_LISPDIR}

INFO=		psgml psgml-api
PLIST_SUB=	PSGML_STARTUP=${PSGML_STARTUP}

SOURCES=	psgml-api.el psgml-charent.el psgml-dtd.el psgml-edit.el \
		psgml-ids.el psgml-info.el psgml-other.el psgml-parse.el \
		psgml-sysdep.el psgml.el
PSGML_STARTUP=	psgml-startup.el
PSGML_LISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}/psgml

do-install:
	@${MKDIR} ${STAGEDIR}${PSGML_LISPDIR}
.for f in ${SOURCES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PSGML_LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/iso88591.map ${STAGEDIR}${PSGML_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

post-install:
	${GZIP_CMD} ${STAGEDIR}${PSGML_LISPDIR}/*.el
	${INSTALL_DATA} ${WRKDIR}/${PSGML_STARTUP} \
	    ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
