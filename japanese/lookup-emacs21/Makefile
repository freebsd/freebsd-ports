# New ports collection makefile for:	lookup for Mule 2.3
# Version required:	1.0
# Date created:		98/11/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	lookup-1.0
PKGNAME?=	ja-lookup-mule-1.0
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/lookup/DIST/

MAINTAINER=	taoka@FreeBSD.org

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS+=	eblook:${PORTSDIR}/japanese/eblook

FILESDIR=	${.CURDIR}/../lookup-mule/files
PKGDIR=		${.CURDIR}/../lookup-mule/pkg
PLIST=		${.CURDIR}/pkg/PLIST
PATCHDIR=	${.CURDIR}/patches
EMACS?=		mule

.if (${EMACS} == "xemacs")
BUILD_DEPENDS+=	xemacs:${PORTSDIR}/japanese/xemacs-canna \
		${PREFIX}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.zenirc:${PORTSDIR}/editors/xemacs-sumo-packages
EMACSDIR=	${PREFIX}/lib/xemacs/site-packages
ELISPDIR=	${EMACSDIR}/lisp/lookup
PORTINFODIR=	${EMACSDIR}/info
MANIFEST=	MANIFEST.lookup
DO_MAKEINFO=	${SETENV} LANG=ja_JP.EUC xemacs -no-site-file -no-init-file \
		-batch -l texinfmt -f batch-texinfo-format lookup.texi; \
		${ECHO} "INFO-DIR-SECTION The Emacs editor and associated tools" >> lookup.info; \
		${ECHO} "START-INFO-DIR-ENTRY" >> lookup.info; \
		${ECHO} "* Lookup: (lookup).             Lookup, a Search Interface." >> lookup.info; \
		${ECHO} "END-INFO-DIR-ENTRY" >> lookup.info
.else
DO_MAKEINFO=	makeinfo --no-split --no-validate lookup.texi
EMACSDIR=	${PREFIX}/share/emacs/site-lisp
ELISPDIR=	${EMACSDIR}/lookup
PORTINFODIR=	${PREFIX}/info
.endif

do-build:
	${RM} ${WRKSRC}/texi/lookup.info*
	nkf -e ${WRKSRC}/texi/lookup.texi > ${WRKSRC}/texi/lookup.euc.texi
	${CP} ${WRKSRC}/texi/lookup.euc.texi ${WRKSRC}/texi/lookup.texi
	(cd ${WRKSRC}/texi/ ; \
		${DO_MAKEINFO} || ${TRUE} ; \
	)

do-install:
	${MKDIR} ${ELISPDIR} ${PORTINFODIR};
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/texi/lookup.info* ${PORTINFODIR}
	${RM} ${ELISPDIR}/lookup-compile.el
	${SED} -e 's,@VERSION@,1.0,' -e 's,@pkgemacsdir@,${ELISPDIR},' \
		${WRKSRC}/lisp/lookup-vars.el.in > ${ELISPDIR}/lookup-vars.el
.if (${EMACS} != "xemacs")
	install-info ${PORTINFODIR}/lookup.info ${PORTINFODIR}/dir
.endif
	${SED} -e 's,%%ELISPDIR%%,${ELISPDIR},' ${FILESDIR}/lookup-startup.el.tmpl > ${ELISPDIR}/../lookup-startup.el

.if (${EMACS} == "xemacs")
post-install:
	${RM} -f ${WRKDIR}/${MANIFEST}
	emacsdir=`${ECHO} ${EMACSDIR} | ${SED} -e "s;^${PREFIX}/;;"`; \
	${CAT} ${PLIST} | ${GREP} -e "^$${emacsdir}" | \
		${SED} -e "s;^$${emacsdir}/;;" > ${WRKDIR}/${MANIFEST}
	${MKDIR} ${EMACSDIR}/pkginfo
	${INSTALL_DATA} ${WRKDIR}/${MANIFEST} \
		${EMACSDIR}/pkginfo/
.endif

.include <bsd.port.mk>
