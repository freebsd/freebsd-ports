# New ports collection makefile for:	X-Emacs Packages
# Date created:		24 Apr 1999
# Whom:			Michael Elbel (me@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xemacs-packages
PORTVERSION=	13.0
CATEGORIES=	editors elisp
MASTER_SITES=	${MASTER_SITE_XEMACS:S|%SUBDIR%|packages|}
DISTFILES=	\
		Sun-1.16-pkg.tar.gz \
		ada-1.14-pkg.tar.gz \
		apel-1.27-pkg.tar.gz \
		auctex-1.46-pkg.tar.gz \
		bbdb-1.25-pkg.tar.gz \
		build-1.14-pkg.tar.gz \
		c-support-1.21-pkg.tar.gz \
		calc-1.26-pkg.tar.gz \
		calendar-1.23-pkg.tar.gz \
		cc-mode-1.43-pkg.tar.gz \
		clearcase-1.09-pkg.tar.gz \
		cookie-1.15-pkg.tar.gz \
		crisp-1.15-pkg.tar.gz \
		debug-1.17-pkg.tar.gz \
		dictionary-1.15-pkg.tar.gz \
		dired-1.17-pkg.tar.gz \
		docbookide-0.07-pkg.tar.gz \
		ecb-1.22-pkg.tar.gz \
		ecrypto-0.19-pkg.tar.gz \
		edebug-1.21-pkg.tar.gz \
		ediff-1.51-pkg.tar.gz \
		edit-utils-2.22-pkg.tar.gz \
		edt-1.13-pkg.tar.gz \
		efs-1.33-pkg.tar.gz \
		eieio-1.05-pkg.tar.gz \
		elib-1.11-pkg.tar.gz \
		emerge-1.11-pkg.tar.gz \
		erc-0.15-pkg.tar.gz \
		escreen-1.01-pkg.tar.gz \
		eshell-1.08-pkg.tar.gz \
		ess-1.14-pkg.tar.gz \
		eterm-1.15-pkg.tar.gz \
		eudc-1.39-pkg.tar.gz \
		footnote-1.16-pkg.tar.gz \
		forms-1.15-pkg.tar.gz \
		fortran-modes-1.04-pkg.tar.gz \
		frame-icon-1.11-pkg.tar.gz \
		fsf-compat-1.15-pkg.tar.gz \
		games-1.15-pkg.tar.gz \
		general-docs-1.03-pkg.tar.gz \
		gnats-1.17-pkg.tar.gz \
		gnus-1.85-pkg.tar.gz \
		haskell-mode-1.07-pkg.tar.gz \
		hm--html-menus-1.23-pkg.tar.gz \
		hyperbole-1.16-pkg.tar.gz \
		ibuffer-1.09-pkg.tar.gz \
		idlwave-1.31-pkg.tar.gz \
		igrep-1.13-pkg.tar.gz \
		ilisp-1.33-pkg.tar.gz \
		ispell-1.31-pkg.tar.gz \
		jde-1.46-pkg.tar.gz \
		mail-lib-1.73-pkg.tar.gz \
		mailcrypt-2.14-pkg.tar.gz \
		mew-1.18-pkg.tar.gz \
		mh-e-1.29-pkg.tar.gz \
		mine-1.16-pkg.tar.gz \
		misc-games-1.18-pkg.tar.gz \
		mmm-mode-1.02-pkg.tar.gz \
		net-utils-1.46-pkg.tar.gz \
		ocaml-0.05-pkg.tar.gz \
		oo-browser-1.04-pkg.tar.gz \
		os-utils-1.36-pkg.tar.gz \
		pc-1.28-pkg.tar.gz \
		pcl-cvs-1.66-pkg.tar.gz \
		pcomplete-1.04-pkg.tar.gz \
		perl-modes-1.08-pkg.tar.gz \
		pgg-1.05-pkg.tar.gz \
		prog-modes-2.03-pkg.tar.gz \
		ps-print-1.11-pkg.tar.gz \
		psgml-1.44-pkg.tar.gz \
		psgml-dtds-1.03-pkg.tar.gz \
		python-modes-1.06-pkg.tar.gz \
		reftex-1.34-pkg.tar.gz \
		re-builder-1.02-pkg.tar.gz \
		riece-1.19-pkg.tar.gz \
		rmail-1.14-pkg.tar.gz \
		ruby-modes-1.02-pkg.tar.gz \
		sasl-1.15-pkg.tar.gz \
		scheme-1.14-pkg.tar.gz \
		semantic-1.19-pkg.tar.gz \
		sgml-1.11-pkg.tar.gz \
		sh-script-1.18-pkg.tar.gz \
		sieve-1.17-pkg.tar.gz \
		slider-1.15-pkg.tar.gz \
		sml-mode-0.11-pkg.tar.gz \
		sounds-au-1.12-pkg.tar.gz \
		sounds-wav-1.12-pkg.tar.gz \
		speedbar-1.27-pkg.tar.gz \
		strokes-1.10-pkg.tar.gz \
		supercite-1.20-pkg.tar.gz \
		texinfo-1.29-pkg.tar.gz \
		text-modes-1.87-pkg.tar.gz \
		textools-1.15-pkg.tar.gz \
		time-1.14-pkg.tar.gz \
		tm-1.38-pkg.tar.gz \
		tooltalk-1.15-pkg.tar.gz \
		tpu-1.14-pkg.tar.gz \
		tramp-1.23-pkg.tar.gz \
		vc-1.40-pkg.tar.gz \
		vc-cc-1.22-pkg.tar.gz \
		vhdl-1.20-pkg.tar.gz \
		view-process-1.13-pkg.tar.gz \
		viper-1.38-pkg.tar.gz \
		vm-7.19-pkg.tar.gz \
		w3-1.30-pkg.tar.gz \
		x-symbol-1.10-pkg.tar.gz \
		xemacs-base-1.97-pkg.tar.gz \
		xemacs-devel-1.70-pkg.tar.gz \
		xetla-1.00-pkg.tar.gz \
		xlib-1.14-pkg.tar.gz \
		xslide-1.09-pkg.tar.gz \
		xslt-process-1.11-pkg.tar.gz \
		xwem-1.21-pkg.tar.gz \
		zenirc-1.15-pkg.tar.gz
DIST_SUBDIR=	xemacs

MAINTAINER=	anrays@gmail.com
COMMENT=	Basic XEmacs elisp packages(xemacs-packages)

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PACKAGES_SUBDIR}

XEMACSDIR=	${PREFIX}/lib/xemacs
PACKAGES_SUBDIR=	xemacs-packages

do-extract:
	@${MKDIR} ${WRKSRC}
.for f in ${DISTFILES}
	-@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/${f} \
		${EXTRACT_AFTER_ARGS} -C ${WRKSRC}
.endfor

post-patch:
	${FIND} ${WRKSRC} -name \*.orig -exec ${RM} -f \{} \;

do-install:
	${MKDIR} ${XEMACSDIR}
	${CP} -R ${WRKSRC} ${XEMACSDIR}

post-install:
	@cd ${WRKDIR} && \
	${FIND} ${PACKAGES_SUBDIR} -type f|${SORT}| \
		${SED} 's:^:lib/xemacs/:' >> ${TMPPLIST}; \
	${FIND} ${PACKAGES_SUBDIR}/*/* -type d|${SORT} -r| \
		${SED} 's:^:@dirrm lib/xemacs/:'>> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xemacs/${PACKAGES_SUBDIR}/* 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xemacs/${PACKAGES_SUBDIR} 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xemacs 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_MSG} "    This port installs packages for XEmacs. These packages should be sufficient"
	@${ECHO_MSG} "for common XEmacs functionality. If you are a non-Latin XEmacs user, installing"
	@${ECHO_MSG} "the xemacs-mule-packages port instead is recommended."
	@${ECHO_MSG} "    You can also install these packages by running XEmacs as root and using the"
	@${ECHO_MSG} "'Manage Packages' menu within the 'Options' menu of the menubar."
	@${ECHO_MSG} "However, installing the packages using this method defeats the purpose of"
	@${ECHO_MSG} "installing this port."

.include <bsd.port.mk>
