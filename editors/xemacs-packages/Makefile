# New ports collection makefile for:	X-Emacs Packages
# Date created:		24 Apr 1999
# Whom:			Michael Elbel (me@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xemacs-packages
PORTVERSION=	1.4
CATEGORIES=	editors elisp
MASTER_SITES=	\
		ftp://ftp.xemacs.org/pub/xemacs/packages/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/packages/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/packages/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/packages/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/packages/

DISTFILES=	\
		apel-1.16-pkg.tar.gz \
		auctex-1.19-pkg.tar.gz \
		c-support-1.14-pkg.tar.gz \
		cc-mode-1.17-pkg.tar.gz \
		debug-1.11-pkg.tar.gz \
		dired-1.07-pkg.tar.gz \
		edit-utils-1.47-pkg.tar.gz \
		efs-1.19-pkg.tar.gz \
		fsf-compat-1.07-pkg.tar.gz \
		hm--html-menus-1.14-pkg.tar.gz \
		ispell-1.18-pkg.tar.gz \
		mail-lib-1.29-pkg.tar.gz \
		mailcrypt-2.04-pkg.tar.gz \
		net-utils-1.13-pkg.tar.gz \
		os-utils-1.20-pkg.tar.gz \
		pcl-cvs-1.46-pkg.tar.gz \
		prog-modes-1.25-pkg.tar.gz \
		ps-print-nomule-1.03-pkg.tar.gz \
		psgml-1.16-pkg.tar.gz \
		sgml-1.06-pkg.tar.gz \
		sh-script-1.11-pkg.tar.gz \
		texinfo-1.19-pkg.tar.gz \
		text-modes-1.25-pkg.tar.gz \
		time-1.09-pkg.tar.gz \
		vc-1.23-pkg.tar.gz \
		viper-1.20-pkg.tar.gz \
		w3-1.15-pkg.tar.gz \
		xemacs-base-1.39-pkg.tar.gz \
		xemacs-devel-1.26-pkg.tar.gz

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

DIST_SUBDIR=	xemacs
MASTER_SITE_SUBDIR=${DIST_SUBDIR}

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
	@${ECHO_MSG} "    This is the basic package for XEmacs(version over 21). You might be enough"
	@${ECHO_MSG} "only with this package for working at XEmacs but if you think it"
	@${ECHO_MSG} "insufficient,you can install other packages provided by XEmacs.org with"
	@${ECHO_MSG} "editors/xemacs-*-packages ports. These ports are prepared for corresponding"
	@${ECHO_MSG} "XEmacs packages except for xemacs-packages, xemacs-mule-basic-packages and"
	@${ECHO_MSG} "xemacs-additional-packages. Where xemacs-additional-packages is a meta ports for"
	@${ECHO_MSG} "packages out of xemacs, xemacs mule-basic and xemacs mule category packages."
	@${ECHO_MSG} "    You can also install with running it as root and using the 'Manage Packes'"
	@${ECHO_MSG} "menu within the 'Options' menu of the menubar. But using this xemacs package"
	@${ECHO_MSG} "managing, you could not control under ports managing ;-)"

.include <bsd.port.mk>
