# New ports collection makefile for:	X-Emacs Packages
# Date created:		24 Apr 1999
# Whom:			Michael Elbel (me@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xemacs-packages
PORTVERSION=	2.1
CATEGORIES=	editors elisp
MASTER_SITES=	${MASTER_SITE_XEMACS} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	packages kiri
DISTFILES=	\
		Sun-1.13-pkg.tar.gz \
		ada-1.10-pkg.tar.gz \
		apel-1.20-pkg.tar.gz \
		auctex-1.28-pkg.tar.gz \
		bbdb-1.16-pkg.tar.gz \
		build-1.03-pkg.tar.gz \
		c-support-1.16-pkg.tar.gz \
		calc-1.17-pkg.tar.gz \
		calendar-1.18-pkg.tar.gz \
		cc-mode-1.26-pkg.tar.gz \
		clearcase-1.00-pkg.tar.gz \
		cookie-1.13-pkg.tar.gz \
		crisp-1.12-pkg.tar.gz \
		debug-1.14-pkg.tar.gz \
		dictionary-1.06-pkg.tar.gz \
		dired-1.11-pkg.tar.gz \
		edebug-1.14-pkg.tar.gz \
		ediff-1.33-pkg.tar.gz \
		edit-utils-1.73-pkg.tar.gz \
		edt-1.12-pkg.tar.gz \
		efs-1.26-pkg.tar.gz \
		eicq-1.05-pkg.tar.gz \
		eieio-1.01-pkg.tar.gz \
		elib-1.08-pkg.tar.gz \
		emerge-1.09-pkg.tar.gz \
		eshell-1.01-pkg.tar.gz \
		eterm-1.13-pkg.tar.gz \
		eudc-1.34-pkg.tar.gz \
		footnote-1.13-pkg.tar.gz \
		forms-1.13-pkg.tar.gz \
		frame-icon-1.09-pkg.tar.gz \
		fsf-compat-1.09-pkg.tar.gz \
		games-1.13-pkg.tar.gz \
		gnats-1.12-pkg.tar.gz \
		gnus-1.57-pkg.tar.gz \
		hm--html-menus-1.16-pkg.tar.gz \
		idlwave-1.23-pkg.tar.gz \
		igrep-1.08-pkg.tar.gz \
		ilisp-1.19-pkg.tar.gz \
		ispell-1.23-pkg.tar.gz \
		jde-1.31-pkg.tar.gz \
		mail-lib-1.40-pkg.tar.gz \
		mailcrypt-2.09-pkg.tar.gz \
		mew-1.14-pkg.tar.gz \
		mh-e-1.13-pkg.tar.gz \
		mine-1.14-pkg.tar.gz \
		misc-games-1.15-pkg.tar.gz \
		net-utils-1.23-pkg.tar.gz \
		os-utils-1.25-pkg.tar.gz \
		pc-1.20-pkg.tar.gz \
		pcl-cvs-1.56-pkg.tar.gz \
		pcomplete-1.01-pkg.tar.gz \
		prog-modes-1.48-pkg.tar.gz \
		ps-print-nomule-1.05-pkg.tar.gz \
		psgml-1.25-pkg.tar.gz \
		reftex-1.23-pkg.tar.gz \
		rmail-1.12-pkg.tar.gz \
		scheme-1.11-pkg.tar.gz \
		semantic-1.10-pkg.tar.gz \
		sgml-1.08-pkg.tar.gz \
		sh-script-1.13-pkg.tar.gz \
		slider-1.13-pkg.tar.gz \
		sounds-au-1.10-pkg.tar.gz \
		sounds-wav-1.10-pkg.tar.gz \
		speedbar-1.21-pkg.tar.gz \
		strokes-1.08-pkg.tar.gz \
		supercite-1.18-pkg.tar.gz \
		texinfo-1.20-pkg.tar.gz \
		text-modes-1.32-pkg.tar.gz \
		textools-1.12-pkg.tar.gz \
		time-1.11-pkg.tar.gz \
		tm-1.29-pkg.tar.gz \
		tooltalk-1.13-pkg.tar.gz \
		tpu-1.12-pkg.tar.gz \
		tramp-1.00-pkg.tar.gz \
		vc-1.30-pkg.tar.gz \
		vc-cc-1.18-pkg.tar.gz \
		vhdl-1.13-pkg.tar.gz \
		view-process-1.11-pkg.tar.gz \
		viper-1.29-pkg.tar.gz \
		vm-7.00-pkg.tar.gz \
		w3-1.20-pkg.tar.gz \
		xemacs-base-1.56-pkg.tar.gz \
		xemacs-devel-1.39-pkg.tar.gz \
		xslt-process-1.05-pkg.tar.gz \
		zenirc-1.11-pkg.tar.gz
DIST_SUBDIR=	xemacs

MAINTAINER=	kiri@FreeBSD.org

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PACKAGES_SUBDIR}

XEMACSDIR=	${PREFIX}/lib/xemacs
PACKAGES_SUBDIR=	xemacs-packages

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
	@${ECHO_MSG} "    This is the set of the packages for xemacs with the xemacs-packages"
	@${ECHO_MSG} "category. You might be enough only with this package(or if you are non-Latin"
	@${ECHO_MSG} "people, together with xemacs-mule-packages) for working at XEmacs but if you"
	@${ECHO_MSG} "think it insufficient,you can install other packages of"
	@${ECHO_MSG} "editors/xemacs-*-packages ports. These ports are prepared for the rack of"
	@${ECHO_MSG} "corresponding XEmacs packages except for xemacs-packages, xemacs-mule-packages"
	@${ECHO_MSG} "and xemacs-additional-packages by which all the additional packages those above"
	@${ECHO_MSG} "will be installed at once."
	@${ECHO_MSG} "    You can also install with running it as root and using the 'Manage Packages'"
	@${ECHO_MSG} "menu within the 'Options' menu of the menubar. But using this xemacs package"
	@${ECHO_MSG} "managing, you could not control under ports managing ;-)"

.include <bsd.port.mk>
