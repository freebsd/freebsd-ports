# New ports collection makefile for:	XEmacs elisp packages for Communication
# Date created:		03 June 2000
# Whom:			KIRIYAMA Kazuhiko<kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xemacs-comm-packages
PORTVERSION=	2.3
CATEGORIES=	editors elisp
MASTER_SITES=	${MASTER_SITE_XEMACS} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	packages kiri
DISTFILES=	\
		bbdb-1.12-pkg.tar.gz \
		eicq-1.03-pkg.tar.gz \
		eudc-1.33-pkg.tar.gz \
		footnote-1.13-pkg.tar.gz \
		gnats-1.12-pkg.tar.gz \
		gnus-1.54-pkg.tar.gz \
		mew-1.14-pkg.tar.gz \
		mh-e-1.13-pkg.tar.gz \
		rmail-1.12-pkg.tar.gz \
		supercite-1.17-pkg.tar.gz \
		tm-1.26-pkg.tar.gz \
		vm-1.28-pkg.tar.gz \
		zenirc-1.09-pkg.tar.gz
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
	@${ECHO_MSG} "    This is the set of the packages for xemacs with the comm category. You can"
	@${ECHO_MSG} "install other packages provided by XEmacs.org with editors/xemacs-*-packages"
	@${ECHO_MSG} "ports. These ports are prepared for corresponding XEmacs packages except for"
	@${ECHO_MSG} "xemacs-packages, xemacs-basic-packages and xemacs-additional-packages. Where"
	@${ECHO_MSG} "xemacs-additional-packages is a meta ports for packages out of xemacs, xemacs"
	@${ECHO_MSG} "mule-basic and xemacs mule category packages."
	@${ECHO_MSG} "    You can also install with running it as root and using the 'Manage Packages'"
	@${ECHO_MSG} "menu within the 'Options' menu of the menubar. But using this xemacs package"
	@${ECHO_MSG} "managing, you could not control under ports managing ;-)"

.include <bsd.port.mk>
