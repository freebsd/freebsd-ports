# New ports collection makefile for:	X-Emacs Packages with Mule
# Date created:		24 Oct 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xemacs-mule-packages
PORTVERSION=	3.5
CATEGORIES=	editors elisp
MASTER_SITES=	${MASTER_SITE_LOCAL:S|%SUBDIR%|kiri/xemacs|} \
		${MASTER_SITE_XEMACS:S|%SUBDIR%|packages|}
DISTFILES=	\
		edict-1.13-pkg.tar.gz \
		egg-its-1.26-pkg.tar.gz \
		latin-unity-1.07-pkg.tar.gz \
		leim-1.20-pkg.tar.gz \
		locale-1.20-pkg.tar.gz \
		lookup-1.13-pkg.tar.gz \
		mule-base-1.43-pkg.tar.gz \
		mule-ucs-1.04-pkg.tar.gz \
		skk-1.23-pkg.tar.gz
DIST_SUBDIR=	xemacs

MAINTAINER=	kiri@FreeBSD.org
COMMENT=	XEmacs elisp packages for Mule(mule-packages)

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PACKAGES_SUBDIR}

XEMACSDIR=	${PREFIX}/lib/xemacs
PACKAGES_SUBDIR=	mule-packages

do-extract:
	@${MKDIR} ${WRKSRC}
.for f in ${DISTFILES}
	-@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/${f} \
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
	@${ECHO_MSG} "    This port installs packages for XEmacs with mule. These packages should be"
	@${ECHO_MSG} "installed altogether with xemacs-packages."
	@${ECHO_MSG} "    You can also install these packages by running XEmacs as root and using the"
	@${ECHO_MSG} "'Manage Packages' menu within the 'Options' menu of the menubar."
	@${ECHO_MSG} "However,installing the packages using this method defeats the purpose of"
	@${ECHO_MSG} "installing this port."

.include <bsd.port.mk>
