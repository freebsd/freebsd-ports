# New ports collection makefile for:	X-Emacs Packages
# Version required:	21.1
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
		xemacs-base-1.30-pkg.tar.gz xemacs-devel-1.21-pkg.tar.gz \
		c-support-1.12-pkg.tar.gz   os-utils-1.15-pkg.tar.gz \
		cc-mode-1.15-pkg.tar.gz     prog-modes-1.19-pkg.tar.gz \
		debug-1.09-pkg.tar.gz       psgml-1.12-pkg.tar.gz \
		dired-1.05-pkg.tar.gz       sgml-1.04-pkg.tar.gz \
		edit-utils-1.39-pkg.tar.gz  text-modes-1.19-pkg.tar.gz \
		efs-1.14-pkg.tar.gz         time-1.07-pkg.tar.gz \
		fsf-compat-1.05-pkg.tar.gz  viper-1.15-pkg.tar.gz \
		mail-lib-1.23-pkg.tar.gz    net-utils-1.11-pkg.tar.gz \
		mailcrypt-1.08-pkg.tar.gz   vc-1.17-pkg.tar.gz \
		sh-script-1.08-pkg.tar.gz  \
		${MULEDISTFILES}

MAINTAINER=	me@FreeBSD.org

DIST_SUBDIR=	xemacs

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

# Have
.if !defined(USE_MULE)
pre-fetch:
	@echo "To install the MULE support files, set the environment variable USE_MULE"
.endif

do-install:
		${MKDIR} ${PREFIX}/lib/xemacs/xemacs-packages
		${CP} -Rp ${WRKDIR}/* ${PREFIX}/lib/xemacs/xemacs-packages

post-install:
	@echo "This is only a subset of the available packages for xemacs."
	@echo "You can install additional packages yourself from within xemacs by"
	@echo "running it as root and using the 'Manage Packes' menu within"
	@echo "the 'Options' menu of the menubar."

.if defined(USE_MULE)
MULEDISTFILES=	mule-base-1.30-pkg.tar.gz
PLIST=		${PKGDIR}/PLIST.mule
.endif

.include <bsd.port.mk>
