# Created by: J Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sml-mode
PORTVERSION=	3.9.5
PORTREVISION=	5
CATEGORIES=	lang elisp
MASTER_SITES=	ftp://ftp.research.bell-labs.com/dist/smlnj/contrib/emacs/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	EMACS mode for editing Standard ML programs

USES=		makeinfo

ALL_TARGET=	default

USE_EMACS=	yes

#
# Install configuration
#

ELISP_SUBDIR=	share/emacs/site-lisp/
SMLMODE_ELISPDIR= ${ELISP_SUBDIR}/sml-mode
SMLMODE_DOCDIR=	share/doc/sml-mode
SMLMODE_DIR_ENTRY=* SML-mode: (sml-mode).         A mode for editing Standard ML programs.

NO_STAGE=	yes
do-install:
	-${MKDIR} ${PREFIX}/${SMLMODE_ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc ${PREFIX}/${SMLMODE_ELISPDIR}/
	(cd ${PREFIX}/${ELISP_SUBDIR} && \
		${LN} -sf sml-mode/sml-mode-startup.el .)
	${INSTALL_DATA} ${WRKSRC}/sml-mode.info ${PREFIX}/info/
	install-info --section="The Emacs editor and associated tools" \
		--entry="${SMLMODE_DIR_ENTRY}" ${PREFIX}/info/sml-mode.info \
		${PREFIX}/info/dir

.include <bsd.port.mk>
