# New ports collection makefile for:	XEmacs elisp packages for Programing
# Date created:		03 June 2000
# Whom:			KIRIYAMA Kazuhiko<kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xemacs-prog-packages
PORTVERSION=	2.4
CATEGORIES=	editors elisp
MASTER_SITES=	${MASTER_SITE_XEMACS} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	packages kiri
DISTFILES=	\
		ada-1.10-pkg.tar.gz \
		ediff-1.29-pkg.tar.gz \
		emerge-1.09-pkg.tar.gz \
		idlwave-1.23-pkg.tar.gz \
		jde-1.24-pkg.tar.gz \
		scheme-1.11-pkg.tar.gz \
		semantic-1.04-pkg.tar.gz \
		vc-cc-1.15-pkg.tar.gz \
		vhdl-1.12-pkg.tar.gz
DIST_SUBDIR=	xemacs

MAINTAINER=	kiri@FreeBSD.org

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/xemacs-packages

XEMACSDIR=	${PREFIX}/lib/xemacs

do-extract:
	@${MKDIR} ${WRKSRC}
.for f in ${DISTFILES}
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/${f} \
		${EXTRACT_AFTER_ARGS} -C ${WRKSRC}
.endfor

do-install:
	${MKDIR} ${XEMACSDIR}
	${CP} -Rp ${WRKDIR}/xemacs-packages ${XEMACSDIR}

post-install:
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
