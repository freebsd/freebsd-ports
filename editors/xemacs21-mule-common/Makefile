# New ports collection makefile for:	files except executables for xemacs with mule
# Date created:		8 Dec 1999
# Whom:			KIRIYAMA Kazuhiko<kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

# This is the COMMON port of XEmacs Mule slave
# ports(editors/xemacs${XEMACS_MAJOR_VER}-mule, japanese/xemacs${XEMACS_MAJOR_VER}-*)
# and provides `Architecture Independent' parts of xemacs binary.
#
# Caracteristic variables of XEmacs Mule ports family:
#	MULE_PORT         : Mule port if defined(means COMMN or SLAVE)
#	MULE_COMMON       : COMMON port if defined
#	MULE_SLAVE        : SLAVE port if defined
#	SITE_INCLUDES     : site include path(configure arguments)
#	SITE_LIBRARIES    : site libraries path(configure arguments)
#	WITH_INPUT_METHOD : input methods(configure arguments)
#	LIB_INPUT_METHOD  : LIB_DEPENDS list of Input Methods
#	BUILD_INPUT_METHOD: BUILD_DEPENDS list of Input Methods
#	WITH_XIM          : X Input Method(configure arguments), xlib or motif

XEMACS_MAJOR_VER=	21

CONFIGURE_ARGS=	--with-x11 \
		--with-mule \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib
MAN1=		ctags.1 etags.1 gnuattach.1 gnuclient.1 gnudoit.1 \
		gnuserv.1 xemacs.1

PKGDIR=		${.CURDIR}/../../editors/xemacs${XEMACS_MAJOR_VER}-mule-common

INSTALL_TARGET=	install-arch-indep
PLIST=		${PKGDIR}/pkg-plist
TMPPLIST=	${WRKDIR}/.PLIST.mktmp-${PKGNAME}

MULE_COMMON=		yes
PKGNAMESUFFIX=		-mule-common
DESCR_TMPL=		${.CURDIR}/../xemacs${XEMACS_MAJOR_VER}-mule-common/files/DESCR.tmpl
INSTALL_TMPL=		${.CURDIR}/../xemacs${XEMACS_MAJOR_VER}-mule-common/files/INSTALL.tmpl
COMMENT_TEXT=		XEmacs(version ${XEMACS_MAJOR_VER}) with mule, lisp files, info pages, etc (except executables)

WRKDIR=	${WRKDIRPREFIX}/${.CURDIR}/../xemacs${XEMACS_MAJOR_VER}-mule/work

pre-build:
	@cd ${.CURDIR}/../xemacs${XEMACS_MAJOR_VER}-mule; ${MAKE}
	@${RM} -f ${WRKSRC}/lib-src/DOC* ${WRKSRC}/src/xemacs

pre-install:
.for dirp in site mule xemacs
.for dir in etc info man pkginfo
	${MKDIR} ${PREFIX}/lib/xemacs/${dirp}-packages/${dir}
.endfor
.endfor
	(cd ${PREFIX}/lib/xemacs; ${MKDIR} info etc site-lisp)

post-install::
	@if [ -f ${PKGINSTALL} ]; then \
		${SETENV} PKG_PREFIX=${PREFIX} \
			${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL; \
	fi
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

## for make DESCR and COMMENT (only maintainer use)
#pre-arrange::
#	${SED}  -e "s/%%XEMACS_VER%%/${XEMACS_VER}/g" \
#		-e "s/%%XEMACS_REL%%/${XEMACS_REL}/g" \
#		${INSTALL_TMPL} > ${PKGINSTALL}
#	${CHOWN} kiri:staff ${PKGINSTALL}

.include "${.CURDIR}/../xemacs${XEMACS_MAJOR_VER}-mule/Makefile"
