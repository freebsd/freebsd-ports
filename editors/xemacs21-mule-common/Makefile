# New ports collection makefile for:	files except executables for xemacs with mule
# Version required:	21.1.8
# Date created:		5 Dec 1997
# Whom:			Kazuyuki IENAGA <ienaga@jsys.co.jp>
#
# $FreeBSD$
#

# This is the COMMON port of XEmacs Mule slave ports(editors/xemacs-mule,
# japanese/xemacs-*) and provides `Architecture Independent' parts of xemacs binary.
#
# Caracteristic variables of XEmacs Mule ports family:
#	MULE_COMMON       : COMMON port if defined
#	PKGLDIR           : Local PKGDIR of MASTER port(editors/xemacs-mule/pkg)
#	SITE_INCLUDES     : site include path(configure arguments)
#	SITE_LIBRARIES    : site libraries path(configure arguments)
#	WITH_INPUT_METHOD : input methods(configure arguments)
#	LIB_INPUT_METHOD  : LIB_DEPENDS list of Input Methods
#	BUILD_INPUT_METHOD: BUILD_DEPENDS list of Input Methods

.include <bsd.port.pre.mk>

.for dir in \
	editors/xemacs-mule \
	japanese/xemacs-canna \
	japanese/xemacs-canna+wnn4 \
	japanese/xemacs-canna+wnn6 \
	japanese/xemacs-wnn4 \
	japanese/xemacs-wnn6
.if exists(${WRKDIRPREFIX}${.CURDIR}/../../${dir}/work/.install_done)
WRKDIR=	${WRKDIRPREFIX}${.CURDIR}/../../${dir}/work
.elif exists(${WRKDIRPREFIX}${.CURDIR}/../../${dir}/work/.build_done)
WRKDIR=	${WRKDIRPREFIX}${.CURDIR}/../../${dir}/work
.endif
.endfor
.if !defined(WRKDIR)
.if defined(PACKAGE_BUILDING)
pre-build:
	@cd ${.CURDIR}/../xemacs-mule; ${MAKE}
.else
BROKEN=		You should build install one of the other xemacs ports first
.endif
.endif

CONFIGURE_ARGS=	--with-x11 \
		--with-mule \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib
MAN1=		ctags.1 etags.1 gnuattach.1 gnuclient.1 gnudoit.1 \
		gnuserv.1 xemacs.1
INSTALL_TARGET=	install-arch-indep
PKGINSTALL=	${WRKDIR}/INSTALL.${PKGNAME}
PLIST=		${PKGDIR}/PLIST
# DESCR=		${WRKDIR}/DESCR.${PKGNAME}
PLIST_SUB=	XEMACS_DIR=${XEMACS_DIR}
PKGINSTALL=	${WRKDIR}/INSTALL
TMPPLIST=	${WRKDIR}/.PLIST.mktmp-${PKGNAME}

MULE_COMMON=	yes
PKGNAMEEXT=	-mule-common
DESCR_TMPL=	${.CURDIR}/../xemacs-mule-common/files/DESCR.tmpl
INSTALL_TMPL=	${.CURDIR}/../xemacs-mule-common/files/INSTALL.tmpl

pre-build:
	@${RM} -f ${WRKSRC}/lib-src/DOC* ${WRKSRC}/src/xemacs

pre-install:
.for dirp in site mule xemacs
.for dir in etc info man pkginfo
	@${MKDIR} ${PREFIX}/lib/xemacs/${dirp}-packages/${dir}
.endfor
.endfor
	@(cd ${PREFIX}/lib/xemacs; ${MKDIR} info etc site-lisp)
	@if [ ! -f ${PREFIX}/lib/xemacs/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/lib/xemacs/info/dir; \
	fi
	@${SED} -e "s/%%XEMACS_VER%%/${XEMACS_VER}/g" \
		${INSTALL_TMPL} > ${PKGINSTALL}

post-install::
# install xemacs-mule.sh into ${PREFIX}/etc/rc.d
	@if [ ! -d /var/run/emacs/lock ]; then \
		${MKDIR} /var/run/emacs/lock; \
		${CHMOD} 1777 /var/run/emacs/lock; \
	fi
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${FILESDIR}/xemacs-mule.sh ${PREFIX}/etc/rc.d
	@if [ -f ${PKGDIR}/INSTALL ]; then \
		${SETENV} PKG_PREFIX=${PREFIX} \
			${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL; \
	fi
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

.include "${.CURDIR}/../xemacs-mule/Makefile"
