# New ports collection makefile for:	X-Emacs Packages with Mule
# Date created:		24 Oct 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xemacs-mule-packages
PORTVERSION=	1.2
CATEGORIES=	editors elisp
MASTER_SITES=	${MASTER_SITE_XEMACS} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	packages kiri
DISTFILES=	\
		edict-1.12-pkg.tar.gz \
		leim-1.17-pkg.tar.gz \
		lookup-1.07-pkg.tar.gz
DIST_SUBDIR=	xemacs

MAINTAINER=	kiri@FreeBSD.org

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/mule-packages

XEMACSDIR=	${PREFIX}/lib/xemacs

do-extract:
	@${MKDIR} ${WRKSRC}
.for f in ${DISTFILES}
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/${f} \
		${EXTRACT_AFTER_ARGS} -C ${WRKSRC}
.endfor

do-install:
	${MKDIR} ${XEMACSDIR}
	${CP} -Rp ${WRKDIR}/mule-packages ${XEMACSDIR}

post-install:
	@${ECHO_MSG} "    This is the set of the packages for xemacs with the mule category. You can"
	@${ECHO_MSG} "install other packages provided by XEmacs.org with editors/xemacs-*-packages"
	@${ECHO_MSG} "ports. These ports are prepared for corresponding XEmacs packages except for"
	@${ECHO_MSG} "xemacs-packages, xemacs-basic-packages and xemacs-additional-packages. Where"
	@${ECHO_MSG} "xemacs-additional-packages is a meta ports for packages out of xemacs, xemacs"
	@${ECHO_MSG} "mule-basic and xemacs mule category packages."
	@${ECHO_MSG} "    You can also install with running it as root and using the 'Manage Packages'"
	@${ECHO_MSG} "menu within the 'Options' menu of the menubar. But using this xemacs package"
	@${ECHO_MSG} "managing, you could not control under ports managing ;-)"

.include <bsd.port.mk>
