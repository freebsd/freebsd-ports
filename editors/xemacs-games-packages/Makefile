# New ports collection makefile for:	X-Emacs Packages
# Date created:		24 Apr 1999
# Whom:			Michael Elbel (me@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xemacs-packages
PORTVERSION=	1.3
CATEGORIES=	editors elisp
MASTER_SITES=	\
		ftp://ftp.xemacs.org/pub/xemacs/packages/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/packages/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/packages/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/packages/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/packages/
DISTFILES=	\
		auctex-1.19-pkg.tar.gz \
		c-support-1.14-pkg.tar.gz \
		cc-mode-1.17-pkg.tar.gz  \
		debug-1.11-pkg.tar.gz  \
		dired-1.07-pkg.tar.gz  \
		edit-utils-1.45-pkg.tar.gz  \
		efs-1.16-pkg.tar.gz   \
		fsf-compat-1.07-pkg.tar.gz \
		hm--html-menus-1.14-pkg.tar.gz \
		ispell-1.18-pkg.tar.gz \
		mail-lib-1.28-pkg.tar.gz \
		mailcrypt-2.04-pkg.tar.gz \
		net-utils-1.13-pkg.tar.gz \
		os-utils-1.19-pkg.tar.gz \
		pcl-cvs-1.41-pkg.tar.gz \
		prog-modes-1.23-pkg.tar.gz \
		ps-print-nomule-1.03-pkg.tar.gz \
		psgml-1.15-pkg.tar.gz \
		sgml-1.06-pkg.tar.gz \
		sh-script-1.11-pkg.tar.gz \
		texinfo-1.18-pkg.tar.gz \
		text-modes-1.22-pkg.tar.gz \
		time-1.09-pkg.tar.gz \
		vc-1.22-pkg.tar.gz \
		viper-1.18-pkg.tar.gz \
		w3-1.15-pkg.tar.gz \
		xemacs-base-1.37-pkg.tar.gz \
		xemacs-devel-1.25-pkg.tar.gz

MAINTAINER=	gj@FreeBSD.org

DIST_SUBDIR=	xemacs

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
	${CP} -Rp ${WRKSRC} ${XEMACSDIR}

post-install:
	@${ECHO_MSG} "This is only a subset of the available packages for xemacs."
	@${ECHO_MSG} "You can install additional packages yourself from within xemacs by"
	@${ECHO_MSG} "running it as root and using the 'Manage Packages' menu within"
	@${ECHO_MSG} "the 'Options' menu of the menubar."
	@${ECHO_MSG} "To install all packages besides basic packages(xemacs-packages or"
	@${ECHO_MSG} "xemacs-mule-packages), consider using the xemacs-sumo-packages or"
	@${ECHO_MSG} "xemacs-mule-sumo-packages port."

.include <bsd.port.mk>
