# New ports collection makefile for:	X-Emacs Packages with Mule
# Date created:		24 Oct 1999
# Whom:			KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xemacs-mule-packages
PORTVERSION=	2.1
CATEGORIES=	editors elisp
MASTER_SITES=	${MASTER_SITE_XEMACS} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	packages kiri
DISTFILES=	\
		edict-1.12-pkg.tar.gz \
		egg-its-1.26-pkg.tar.gz \
		leim-1.17-pkg.tar.gz \
		locale-1.18-pkg.tar.gz \
		lookup-1.08-pkg.tar.gz \
		mule-base-1.39-pkg.tar.gz \
		mule-ucs-1.00-pkg.tar.gz \
		skk-1.19-pkg.tar.gz
DIST_SUBDIR=	xemacs

MAINTAINER=	kiri@FreeBSD.org

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
	find ${PACKAGES_SUBDIR} -type f|sort|${SED} 's:^:lib/xemacs/:' >> ${TMPPLIST}; \
	find ${PACKAGES_SUBDIR}/*/* -type d|sort -r|${SED} 's:^:@dirrm lib/xemacs/:'>> ${TMPPLIST}
	@${ECHO} '@unexec rmdir %D/lib/xemacs/${PACKAGES_SUBDIR}/* 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO} '@unexec rmdir %D/lib/xemacs/${PACKAGES_SUBDIR} 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO} '@unexec rmdir %D/lib/xemacs 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_MSG} "    This is the set of the packages for xemacs with the mule-packages category."
	@${ECHO_MSG} "You might be enough with this package installing xemacs-packages altogether for"
	@${ECHO_MSG} "working at XEmacs but if you think it insufficient,you can install other"
	@${ECHO_MSG} "packages of editors/xemacs-*-packages ports. These ports are prepared for the"
	@${ECHO_MSG} "rack of corresponding XEmacs packages except for"
	@${ECHO_MSG} "xemacs-packages,xemacs-mule-packages and xemacs-additional-packages by which all"
	@${ECHO_MSG} "the additional packages those above will be installed at once."
	@${ECHO_MSG} "    You can also install with running it as root and using the 'Manage Packages'"
	@${ECHO_MSG} "menu within the 'Options' menu of the menubar. But using this xemacs package"
	@${ECHO_MSG} "managing, you could not control under ports managing ;-)"

.include <bsd.port.mk>
