# New ports collection makefile for:	sml-mode.el
# Date created:		23 December 1999
# Whom:			J Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sml-mode
PORTVERSION=	3.3
CATEGORIES=	lang elisp
MASTER_SITES=	ftp://ftp.research.bell-labs.com/dist/smlnj/contrib/emacs/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jkoshy@FreeBSD.org

NO_BUILD=	yes

#
# Install configuration
#

ELISP_SUBDIR=	share/emacs/site-lisp/
SMLMODE_ELISPDIR= ${ELISP_SUBDIR}/sml-mode
SMLMODE_DOCDIR=	share/doc/sml-mode
SMLMODE_DIR_ENTRY=* SML-mode: (sml-mode).         A mode for editing Standard ML programs.

do-install:
	-${MKDIR} ${PREFIX}/${SMLMODE_ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${PREFIX}/${SMLMODE_ELISPDIR}/
	(cd ${PREFIX}/${ELISP_SUBDIR} && \
		${LN} -sf sml-mode/sml-site.el .)
.if !defined(NOPORTDOCS)
	-${MKDIR} ${PREFIX}/${SMLMODE_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sml-mode.html ${PREFIX}/${SMLMODE_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sml-mode.ps ${PREFIX}/${SMLMODE_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sml-mode.info ${PREFIX}/info/
	install-info --section="The Emacs editor and associated tools" \
		--entry="${SMLMODE_DIR_ENTRY}" ${PREFIX}/info/sml-mode.info \
		${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
