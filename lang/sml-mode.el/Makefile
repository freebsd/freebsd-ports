# New ports collection makefile for:	sml-mode.el
# Date created:		23 December 1999
# Whom:			J Koshy <jkoshy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sml-mode
PORTVERSION=	3.9.5
CATEGORIES=	lang elisp
MASTER_SITES=	ftp://ftp.research.bell-labs.com/dist/smlnj/contrib/emacs/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	An EMACS mode for editing Standard ML programs

ALL_TARGET=	default

EMACS_PORT_NAME=	emacs21

#
# Install configuration
#

ELISP_SUBDIR=	share/emacs/site-lisp/
SMLMODE_ELISPDIR= ${ELISP_SUBDIR}/sml-mode
SMLMODE_DOCDIR=	share/doc/sml-mode
SMLMODE_DIR_ENTRY=* SML-mode: (sml-mode).         A mode for editing Standard ML programs.

do-install:
	-${MKDIR} ${PREFIX}/${SMLMODE_ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc ${PREFIX}/${SMLMODE_ELISPDIR}/
	(cd ${PREFIX}/${ELISP_SUBDIR} && \
		${LN} -sf sml-mode/sml-mode-startup.el .)
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/sml-mode.info ${PREFIX}/info/
	install-info --section="The Emacs editor and associated tools" \
		--entry="${SMLMODE_DIR_ENTRY}" ${PREFIX}/info/sml-mode.info \
		${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
