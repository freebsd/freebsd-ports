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
#	SITE_INCLUDES     : site include path(configure arguments)
#	SITE_LIBRARIES    : site libraries path(configure arguments)
#	WITH_INPUT_METHOD : input methods(configure arguments)
#	LIB_INPUT_METHOD  : LIB_DEPENDS list of Input Methods
#	BUILD_INPUT_METHOD: BUILD_DEPENDS list of Input Methods
#	WITH_XIM          : X Input Method(configure arguments), xlib or motif

CATEGORIES=	japanese

MANLANG=	ja
MAN1=		xemacs-ja.1
COMMENT?=	${.CURDIR}/../xemacs${XEMACS_MAJOR_VER}-canna/pkg-comment
DESCR=		${.CURDIR}/../xemacs${XEMACS_MAJOR_VER}-canna/pkg-descr

XEMACS_MAJOR_VER?=	21
DESCR_TMPL=		${.CURDIR}/../xemacs${XEMACS_MAJOR_VER}-canna/files/DESCR.tmpl
.if defined(CANNA) && defined(FREEWNN)
PKGNAMESUFFIX=		-canna+freewnn
WITH_INPUT_METHOD=	--with-canna --with-wnn --with-wnn6=no
LIB_INPUT_METHOD=	canna.1:${PORTSDIR}/japanese/Canna \
			wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
COMMENT_TEXT=		XEmacs(version ${XEMACS_MAJOR_VER}) text editor, with SJ3, SKK, Canna and FreeWnn support
.elif defined(CANNA) && defined(WNN6)
PKGNAMESUFFIX=		-canna+wnn6
SITE_INCLUDES=		${LOCALBASE}/include/wnn6
WITH_INPUT_METHOD=	--with-canna --with-wnn6
LIB_INPUT_METHOD=	canna.1:${PORTSDIR}/japanese/Canna \
			wnn6.1:${PORTSDIR}/japanese/Wnn6-lib
COMMENT_TEXT=		XEmacs(version ${XEMACS_MAJOR_VER}) text editor, with SJ3, SKK, Canna and Wnn6 support
.elif defined(FREEWNN)
PKGNAMESUFFIX=		-freewnn
WITH_INPUT_METHOD=	--with-wnn --with-canna=no --with-wnn6=no
LIB_INPUT_METHOD=	wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
COMMENT_TEXT=		XEmacs(version ${XEMACS_MAJOR_VER}) text editor, with SJ3, SKK and FreeWnn support
.elif defined(WNN6)
PKGNAMESUFFIX=		-wnn6
SITE_INCLUDES=		${LOCALBASE}/include/wnn6
WITH_INPUT_METHOD=	--with-wnn6 --with-canna=no
LIB_INPUT_METHOD=	wnn6.1:${PORTSDIR}/japanese/Wnn6-lib
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
