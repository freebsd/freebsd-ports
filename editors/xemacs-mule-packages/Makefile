# New ports collection makefile for:	X-Emacs Packages with Mule
# Version required:	1.0
# Date created:		24 Oct 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	xemacs-mule-packages
PKGNAME=	xemacs-mule-packages-1.0
CATEGORIES=	editors
MASTER_SITES=	\
		ftp://ftp.xemacs.org/pub/xemacs/packages/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/packages/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/packages/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/packages/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/packages/ \
		${MASTER_SITE_PORTS_JP}

# These are not smallest set of packages but mostly usage of packages for
# many `Mule' users.
DISTFILES=	\
		mule-base-1.32-pkg.tar.gz	locale-1.14-pkg.tar.gz \
		apel-1.15-pkg.tar.gz 		mew-1.08-pkg.tar.gz \
		skk-1.14-pkg.tar.gz		elib-1.05-pkg.tar.gz \
		egg-its-1.20-pkg.tar.gz		ps-print-ja-1.01-pkg.tar.gz

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

DIST_SUBDIR=	xemacs
MASTER_SITE_SUBDIR=${DIST_SUBDIR}

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

XEMACSDIR=	${PREFIX}/lib/xemacs/mule-packages

do-install:
	${MKDIR} ${XEMACSDIR}
	${CP} -Rp ${WRKDIR}/* ${XEMACSDIR}

post-install:
	@${ECHO_MSG} "This is only a subset of the available packages for xemacs"
	@${ECHO_MSG} "with mule."
	@${ECHO_MSG} "You can install additional packages yourself from within xemacs by"
	@${ECHO_MSG} "running it as root and using the 'Manage Packes' menu within"
	@${ECHO_MSG} "the 'Options' menu of the menubar."
	@${ECHO_MSG} "To install all packages with mule, consider using the"
	@${ECHO_MSG} "xemacs-sumo-packages and xemacs-mule-sumo-packages ports."

.include <bsd.port.mk>
