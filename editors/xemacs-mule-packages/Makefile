# New ports collection makefile for:	X-Emacs Packages with Mule
# Date created:		24 Oct 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xemacs-mule-packages
PORTVERSION=	1.1
CATEGORIES=	editors elisp
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
		mule-base-1.34-pkg.tar.gz	locale-1.15-pkg.tar.gz \
		skk-1.15-pkg.tar.gz		elib-1.06-pkg.tar.gz \
		egg-its-1.22-pkg.tar.gz		ps-print-ja-1.01-pkg.tar.gz

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

DIST_SUBDIR=	xemacs
MASTER_SITE_SUBDIR=${DIST_SUBDIR}

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
	@${ECHO_MSG} "This is only a subset of the available packages for xemacs"
	@${ECHO_MSG} "with mule."
	@${ECHO_MSG} "You can install additional packages yourself from within xemacs by"
	@${ECHO_MSG} "running it as root and using the 'Manage Packes' menu within"
	@${ECHO_MSG} "the 'Options' menu of the menubar."
	@${ECHO_MSG} "To install all packages besides basic packages(xemacs-packages or"
	@${ECHO_MSG} "xemacs-mule-packages), consider using the xemacs-other-packages or"
	@${ECHO_MSG} "xemacs-mule-other-packages port."

## for make PLIST (only maintainer use)
#arrange:
#	${MAKE} -DPLIST_OVERRIDE DIRRM2RMDIRS="lib/xemacs/mule-packages/pkginfo lib/xemacs/mule-packages/man lib/xemacs/mule-packages/lisp lib/xemacs/mule-packages/info lib/xemacs/mule-packages/etc lib/xemacs/mule-packages" \
#		DIRRMDEPTH=2 plist

.include <bsd.port.mk>
