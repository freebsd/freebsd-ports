# New ports collection makefile for:	XEmacs for Japanese
# Date created:		5 Dec 1997
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

# This is the MASTER port of Japanese XEmacs slave ports
# (japanese/xemacs${XEMACS_MAJOR_VER}-*) and provides `Architecture Dependent' parts
# of xemacs binary. 
#
# Caracteristic variables of XEmacs Mule ports family:
#	MULE_PORT         : Mule port if defined(means COMMN or SLAVE)
#	MULE_COMMON       : COMMON port if defined
#	MULE_SLAVE        : SLAVE port if defined
#	PKGLDIR           : Local PKGDIR of editors/xemacs${XEMACS_MAJOR_VER}-mule
#                           (that is editors/xemacs${XEMACS_MAJOR_VER}-mule/pkg)
#	SITE_INCLUDES     : site include path(configure arguments)
#	SITE_LIBRARIES    : site libraries path(configure arguments)
#	WITH_INPUT_METHOD : input methods(configure arguments)
#	LIB_INPUT_METHOD  : LIB_DEPENDS list of Input Methods
#	BUILD_INPUT_METHOD: BUILD_DEPENDS list of Input Methods

CATEGORIES=	japanese editors

MANLANG=	ja
MAN1=		xemacs-ja.1
DESCR=		${.CURDIR}/../xemacs${XEMACS_MAJOR_VER}-canna/pkg/DESCR

XEMACS_MAJOR_VER?=	21
DESCR_TMPL=		${.CURDIR}/../xemacs${XEMACS_MAJOR_VER}-canna/files/DESCR.tmpl
.if defined(CANNA) && defined(WNN4)
PKGNAMESUFFIX=		-canna+wnn4
SITE_INCLUDES=		${X11BASE}/include
SITE_LIBRARIES=		${X11BASE}/lib
WITH_INPUT_METHOD=	--with-canna --with-wnn --with-wnn6=no
LIB_INPUT_METHOD=	canna.1:${PORTSDIR}/japanese/Canna
BUILD_INPUT_METHOD=	${PREFIX}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
COMMENT_TEXT=		XEmacs(version ${XEMACS_MAJOR_VER}) text editor, with SJ3, SKK, Canna and Wnn4 support
.elif defined(CANNA) && defined(WNN6)
PKGNAMESUFFIX=		-canna+wnn6
WITH_INPUT_METHOD=	--with-canna --with-wnn6
LIB_INPUT_METHOD=	canna.1:${PORTSDIR}/japanese/Canna
BUILD_INPUT_METHOD=	${PREFIX}/include/wnn/jlib.h:${PORTSDIR}/japanese/Wnn6-lib
COMMENT_TEXT=		XEmacs(version ${XEMACS_MAJOR_VER}) text editor, with SJ3, SKK, Canna and Wnn6 support
.elif defined(WNN4)
PKGNAMESUFFIX=		-wnn4
SITE_INCLUDES=		${X11BASE}/include
SITE_LIBRARIES=		${X11BASE}/lib
WITH_INPUT_METHOD=	--with-wnn --with-canna=no --with-wnn6=no
BUILD_INPUT_METHOD=	${PREFIX}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
COMMENT_TEXT=		XEmacs(version ${XEMACS_MAJOR_VER}) text editor, with SJ3, SKK and Wnn4 support
.elif defined(WNN6)
PKGNAMESUFFIX=		-wnn6
WITH_INPUT_METHOD=	--with-wnn6 --with-canna=no
BUILD_INPUT_METHOD=	${PREFIX}/include/wnn/jlib.h:${PORTSDIR}/japanese/Wnn6-lib
COMMENT_TEXT=		XEmacs(version ${XEMACS_MAJOR_VER}) text editor, with SJ3, SKK and Wnn6 support
.else
PKGNAMESUFFIX=		-canna
WITH_INPUT_METHOD=	--with-canna --with-wnn=no --with-wnn6=no
LIB_INPUT_METHOD=	canna.1:${PORTSDIR}/japanese/Canna
COMMENT_TEXT=		XEmacs(version ${XEMACS_MAJOR_VER}) text editor, with SJ3, SKK and Canna support
.endif

post-install::
	@${MKDIR} ${PREFIX}/man/ja/man1
	@${INSTALL_MAN} ${WRKSRC}/etc/xemacs-ja.1 ${PREFIX}/man/ja/man1

.include "${.CURDIR}/../../editors/xemacs${XEMACS_MAJOR_VER}-mule/Makefile"
