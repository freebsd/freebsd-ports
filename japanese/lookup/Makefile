# New ports collection makefile for:	lookup for Mule 2.3
# Date created:		98/11/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lookup
PORTVERSION=	1.2
PKGNAMESUFFIX?=	-mule
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/lookup/DIST/

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS+=	eblook:${PORTSDIR}/japanese/eblook

FILESDIR=	${.CURDIR}/../lookup-mule/files
PKGDIR=		${.CURDIR}/../lookup-mule/pkg
PLIST=		${.CURDIR}/pkg/PLIST
PATCHDIR=	${.CURDIR}/patches
EMACS?=		mule

.if (${EMACS} == "xemacs")
EMACSDIR=	${PREFIX}/lib/xemacs/site-packages
ELISPDIR=	${EMACSDIR}/lisp/lookup
PORTINFODIR=	${EMACSDIR}/info
MANIFEST=	MANIFEST.lookup
.else
EMACSDIR=	${PREFIX}/share/emacs/site-lisp
ELISPDIR=	${EMACSDIR}/lookup
PORTINFODIR=	${PREFIX}/info
.endif
NO_BUILD=	yes

do-install:
	${MKDIR} ${ELISPDIR} ${PORTINFODIR};
	${INSTALL_DATA} ${WRKSRC}/lisp/*.el ${ELISPDIR}
	${RM} ${ELISPDIR}/lookup-compile.el
	${SED} -e 's,@VERSION@,${PORTVERSION},' -e 's,@pkgemacsdir@,${ELISPDIR},' \
		${WRKSRC}/lisp/lookup-vars.el.in > ${ELISPDIR}/lookup-vars.el
	${INSTALL_DATA} ${WRKSRC}/texi/lookup.info* ${PORTINFODIR}
	${INSTALL_DATA} ${WRKSRC}/texi/lookup-guide.info ${PORTINFODIR}
.if (${EMACS} != "xemacs")
	install-info ${PORTINFODIR}/lookup.info ${PORTINFODIR}/dir
	install-info ${PORTINFODIR}/lookup-guide.info ${PORTINFODIR}/dir
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
