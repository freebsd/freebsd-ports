# New ports collection makefile for:	XEmacs elisp packages for Programing
# Date created:		03 June 2000
# Whom:			KIRIYAMA Kazuhiko<kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xemacs-prog-packages
PORTVERSION=	2.6
CATEGORIES=	editors elisp
MASTER_SITES=	${MASTER_SITE_XEMACS} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	packages kiri
DISTFILES=	\
		ada-1.10-pkg.tar.gz \
		ediff-1.31-pkg.tar.gz \
		emerge-1.09-pkg.tar.gz \
		idlwave-1.23-pkg.tar.gz \
		jde-1.27-pkg.tar.gz \
		scheme-1.11-pkg.tar.gz \
		semantic-1.06-pkg.tar.gz \
		vc-cc-1.16-pkg.tar.gz \
		vhdl-1.13-pkg.tar.gz
DIST_SUBDIR=	xemacs

MAINTAINER=	kiri@FreeBSD.org

RUN_DEPENDS=	${XEMACSDIR}/mule-packages/lisp/elib/avltree.el:${.CURDIR}/../xemacs-basic-mule-packages

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PACKAGES_SUBDIR}

XEMACSDIR=	${PREFIX}/lib/xemacs
PACKAGES_SUBDIR=	xemacs-packages

do-extract:
	@${MKDIR} ${WRKSRC}
.for f in ${DISTFILES}
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/${f} \
		${EXTRACT_AFTER_ARGS} -C ${WRKSRC}
.endfor

do-install:
	${MKDIR} ${XEMACSDIR}
	${CP} -R ${WRKSRC} ${XEMACSDIR}

post-install:
	@cd ${WRKDIR} && \
	${FIND} ${PACKAGES_SUBDIR} -type f|sort|${SED} 's:^:lib/xemacs/:' >> ${TMPPLIST}; \
	${FIND} ${PACKAGES_SUBDIR}/*/* -type d|sort -r|${SED} 's:^:@dirrm lib/xemacs/:'>> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xemacs/${PACKAGES_SUBDIR}/* 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xemacs/${PACKAGES_SUBDIR} 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xemacs 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_MSG} "    This is the set of the packages for xemacs with the prog category. You can"
	@${ECHO_MSG} "install other packages provided by XEmacs.org with editors/xemacs-*-packages"
	@${ECHO_MSG} "ports. These ports are prepared for corresponding XEmacs packages except for"
	@${ECHO_MSG} "xemacs-packages, xemacs-basic-packages and xemacs-additional-packages. Where"
	@${ECHO_MSG} "xemacs-additional-packages is a meta ports for packages out of xemacs, xemacs"
	@${ECHO_MSG} "mule-basic and xemacs mule category packages."
	@${ECHO_MSG} "    You can also install with running it as root and using the 'Manage Packages'"
	@${ECHO_MSG} "menu within the 'Options' menu of the menubar. But using this xemacs package"
	@${ECHO_MSG} "managing, you could not control under ports managing ;-)"

.include <bsd.port.mk>
