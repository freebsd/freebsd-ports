# New ports collection makefile for:	X-Emacs Packages with Mule
# Date created:		24 Oct 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xemacs-mule-packages
PORTVERSION=	3.4
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
		mule-base-1.42-pkg.tar.gz \
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
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/${f} \
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
	@${ECHO_MSG} "    This is the set of the packages for xemacs with the mule-packages category."
	@${ECHO_MSG} "You can get all packages altogether with installing xemacs-packages and work"
	@${ECHO_MSG} "fine at XEmacs."
	@${ECHO_MSG} "    You can also install with running it as root and using the 'Manage Packages'"
	@${ECHO_MSG} "menu within the 'Options' menu of the menubar. But using this xemacs package"
	@${ECHO_MSG} "managing, you could not control under ports managing ;-)"

.include <bsd.port.mk>
