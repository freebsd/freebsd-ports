# New ports collection makefile for:	color-mate for emacs
# Date created:		99/09/29
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	color-mate
PORTVERSION=	10.5
CATEGORIES=	editors elisp
MASTER_SITES=	http://www.netlab.is.tsukuba.ac.jp/~yokota/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Color customizing module for Emacsen

BUILD_DEPENDS=	lndir:${PORTSDIR}/x11/XFree86 \
		showrgb:${PORTSDIR}/x11/XFree86

USE_PERL5=	yes

EMACSDIR=	${PREFIX}/share/emacs/site-lisp
ELISPDIR=	${EMACSDIR}/color-mate
SITEPKGDIR=	${PREFIX}/lib/xemacs/site-packages
XELISPDIR=	${SITEPKGDIR}/lisp/color-mate
THEME_DIR=	${ELISPDIR}/theme
DOCDIR=		${PREFIX}/share/doc/color-mate
MANIFEST=	MANIFEST.color-mate

do-build:
# Create color-mate-rgb.el
	cd ${WRKSRC}; \
	(showrgb | ${PERL5} ./rgb2el.pl > ./color-mate-rgb.el ) || ( ${ECHO} "Make rgb table from color-mate-rgb.el.std" ; ${CP} ./color-mate-rgb.el.std ./color-mate-rgb.el)
# Create Xresource for theme
	cd ${WRKSRC}/theme; \
	${SH} ${FILESDIR}/theme_build.sh
	${SED} -e 's,@INSTALLPATH@,${XELISPDIR},' ${WRKSRC}/Dot.emacs.default.in \
		> ${WRKDIR}/color-mate-startup.el
	${ECHO_CMD} "(provide 'color-mate-startup)" >> ${WRKDIR}/color-mate-startup.el
	${SED} -e 's,@INSTALLPATH@,${XELISPDIR},' ${WRKSRC}/Dot.emacs.default.in \
		> ${WRKDIR}/color-mate-startup.xemacs.el
	${ECHO_CMD} "(provide 'color-mate-startup)" >> ${WRKDIR}/color-mate-startup.xemacs.el

do-install:
	${MKDIR} ${ELISPDIR} ${DOCDIR} ${THEME_DIR} ${XELISPDIR} ${ELISPDIR}/kanakan-cursor ${ELISPDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/*.el ${ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/kanakan-cursor/*.el ${ELISPDIR}/kanakan-cursor/
	${INSTALL_DATA} ${WRKSRC}/contrib/*.el ${ELISPDIR}/contrib/
	${INSTALL_DATA} ${WRKSRC}/contrib/README ${ELISPDIR}/contrib/
	${INSTALL_DATA} ${WRKSRC}/contrib/cm_select.sh.in ${ELISPDIR}/contrib/
	${INSTALL_DATA} ${WRKSRC}/theme/* ${THEME_DIR}
	${RM} ${THEME_DIR}/Makefile*
	${MV} ${THEME_DIR}/README ${THEME_DIR}/README.jp
	${INSTALL_SCRIPT} ${FILESDIR}/theme_build.sh ${THEME_DIR}
	${INSTALL_DATA} ${WRKDIR}/color-mate-startup.el ${ELISPDIR}/../
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README.color-mate ${DOCDIR}/README.color-mate.jp
	${INSTALL_DATA} ${WRKSRC}/README.color-mate.eng ${DOCDIR}/README.color-mate.eng
	${INSTALL_DATA} ${WRKSRC}/Q_and_A.color-mate  ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/QuickStart.color-mate ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Customize.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Dot.emacs.default.in ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/kanakan-cursor/README.kanakan-cursor ${DOCDIR}/README.kanakan-cursor.jp
	${INSTALL_DATA} ${WRKSRC}/kanakan-cursor/README.kanakan-cursor.eng ${DOCDIR}/README.kanakan-cursor.eng
.endif
#
# For XEmacs
	cd ${XELISPDIR}; lndir ${ELISPDIR}
	${RM} -f ${WRKDIR}/${MANIFEST}
	emacsdir=`${ECHO_CMD} ${SITEPKGDIR} | ${SED} -e "s;^${PREFIX}/;;"`; \
	${CAT} ${PLIST} | ${GREP} -e "^$${emacsdir}" | \
		 ${SED} -e "s;^$${emacsdir}/;;" > ${WRKDIR}/${MANIFEST}
	${MKDIR} ${SITEPKGDIR}/pkginfo
	${INSTALL_DATA} ${WRKDIR}/${MANIFEST} ${SITEPKGDIR}/pkginfo/
	${INSTALL_DATA} ${WRKDIR}/color-mate-startup.xemacs.el ${XELISPDIR}/../color-mate-startup.el

.include <bsd.port.mk>
