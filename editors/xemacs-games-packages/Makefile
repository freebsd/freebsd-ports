# New ports collection makefile for:	X-Emacs Packages
# Version required:	1.0
# Date created:		24 Apr 1999
# Whom:			Michael Elbel (me@FreeBSD.org)
#
# $FreeBSD$
#

DISTNAME=	xemacs-packages
PKGNAME=	xemacs-packages-1.0
CATEGORIES=	editors
MASTER_SITES=	\
		ftp://ftp.xemacs.org/pub/xemacs/packages/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/packages/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/packages/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/packages/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/packages/
DISTFILES=	\
		xemacs-base-1.32-pkg.tar.gz xemacs-devel-1.23-pkg.tar.gz \
		c-support-1.13-pkg.tar.gz   os-utils-1.18-pkg.tar.gz \
		cc-mode-1.16-pkg.tar.gz     prog-modes-1.21-pkg.tar.gz \
		debug-1.10-pkg.tar.gz       psgml-1.14-pkg.tar.gz \
		dired-1.06-pkg.tar.gz       sgml-1.05-pkg.tar.gz \
		edit-utils-1.41-pkg.tar.gz  text-modes-1.21-pkg.tar.gz \
		efs-1.15-pkg.tar.gz         time-1.08-pkg.tar.gz \
		fsf-compat-1.06-pkg.tar.gz  viper-1.17-pkg.tar.gz \
		mail-lib-1.24-pkg.tar.gz    net-utils-1.12-pkg.tar.gz \
		mailcrypt-2.02-pkg.tar.gz   vc-1.19-pkg.tar.gz \
		sh-script-1.10-pkg.tar.gz   auctex-1.17-pkg.tar.gz \
		ispell-1.16-pkg.tar.gz      pcl-cvs-1.40-pkg.tar.gz \
		w3-1.14-pkg.tar.gz

MAINTAINER=	me@FreeBSD.org

DIST_SUBDIR=	xemacs

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
		${MKDIR} ${PREFIX}/lib/xemacs/xemacs-packages
		${CP} -Rp ${WRKDIR}/* ${PREFIX}/lib/xemacs/xemacs-packages

post-install:
	@${ECHO_MSG} "This is only a subset of the available packages for xemacs."
	@${ECHO_MSG} "You can install additional packages yourself from within xemacs by"
	@${ECHO_MSG} "running it as root and using the 'Manage Packes' menu within"
	@${ECHO_MSG} "the 'Options' menu of the menubar."
	@${ECHO_MSG} "To install all packages, consider using the xemacs-sumo-packages"
	@${ECHO_MSG} "and xemacs-mule-sumo-packages ports."

.include <bsd.port.mk>
