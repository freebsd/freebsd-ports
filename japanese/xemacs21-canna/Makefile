# New ports collection makefile for:	XEmacs for Japanese
# Version required:	21.1.8
# Date created:		5 Dec 1997
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

# This is the MASTER port of Japanese XEmacs slave ports(japanese/xemacs-*)
# and provides `Architecture Dependent' parts of xemacs binary. 
#
# Caracteristic variables of XEmacs Mule ports family:
#	MULE_COMMON       : COMMON port if defined
#	PKGLDIR           : Local PKGDIR of MASTER port(editors/xemacs-mule/pkg)
#	SITE_INCLUDES     : site include path(configure arguments)
#	SITE_LIBRARIES    : site libraries path(configure arguments)
#	WITH_INPUT_METHOD : input methods(configure arguments)
#	LIB_INPUT_METHOD  : LIB_DEPENDS list of Input Methods
#	BUILD_INPUT_METHOD: BUILD_DEPENDS list of Input Methods

CATEGORIES=	japanese editors

MANLANG=	ja
MAN1=		xemacs-ja.1
DESCR=		${.CURDIR}/../xemacs-canna/pkg/DESCR
PLIST=		${PKGLDIR}/PLIST-ja

DESCR_TMPL=	${.CURDIR}/../xemacs-canna/files/DESCR.tmpl
LANGPREFIX=	ja-
.if defined(CANNA) && defined(WNN4)
PKGNAMEEXT=		-canna+wnn4
SITE_INCLUDES=		${X11BASE}/include
SITE_LIBRARIES=		${X11BASE}/lib
WITH_INPUT_METHOD=	--with-canna --with-wnn --with-wnn6=no
LIB_INPUT_METHOD=	canna.1:${PORTSDIR}/japanese/Canna
BUILD_INPUT_METHOD=	${PREFIX}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
COMMENT_TEXT=		XEmacs(version ${XEMACS_VER}) text editor, with SJ3, SKK, Canna and Wnn4 support.
.elif defined(CANNA) && defined(WNN6)
PKGNAMEEXT=		-canna+wnn6
WITH_INPUT_METHOD=	--with-canna --with-wnn6
LIB_INPUT_METHOD=	canna.1:${PORTSDIR}/japanese/Canna
BUILD_INPUT_METHOD=	${PREFIX}/include/wnn/jlib.h:${PORTSDIR}/japanese/Wnn6-lib
COMMENT_TEXT=		XEmacs(version ${XEMACS_VER}) text editor, with SJ3, SKK, Canna and Wnn6 support.
.elif defined(WNN4)
PKGNAMEEXT=		-wnn4
SITE_INCLUDES=		${X11BASE}/include
SITE_LIBRARIES=		${X11BASE}/lib
WITH_INPUT_METHOD=	--with-wnn --with-canna=no --with-wnn6=no
BUILD_INPUT_METHOD=	${PREFIX}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
COMMENT_TEXT=		XEmacs(version ${XEMACS_VER}) text editor, with SJ3, SKK and Wnn4 support.
.elif defined(WNN6)
PKGNAMEEXT=		-wnn6
WITH_INPUT_METHOD=	--with-wnn6 --with-canna=no
BUILD_INPUT_METHOD=	${PREFIX}/include/wnn/jlib.h:${PORTSDIR}/japanese/Wnn6-lib
COMMENT_TEXT=		XEmacs(version ${XEMACS_VER}) text editor, with SJ3, SKK and Wnn6 support.
.else
PKGNAMEEXT=		-canna
WITH_INPUT_METHOD=	--with-canna --with-wnn=no --with-wnn6=no
LIB_INPUT_METHOD=	canna.1:${PORTSDIR}/japanese/Canna
COMMENT_TEXT=		XEmacs(version ${XEMACS_VER}) text editor, with SJ3, SKK and Canna support.
.endif

post-install::
	@${MKDIR} ${PREFIX}/man/ja/man1
	@${INSTALL_MAN} ${WRKSRC}/etc/xemacs-ja.1 ${PREFIX}/man/ja/man1
	@${LN} -sf ja ${PREFIX}/lib/xemacs/mule-packages/etc/app-defaults/ja_JP.EUC

# for make COMMENT (only maintainer use)
arrange::
	@${MKDIR} ${PKGDIR} ${.CURDIR}/../xemacs-canna/pkg
	@${ECHO} "${COMMENT_TEXT}" > ${COMMENT}

.include "${.CURDIR}/../../editors/xemacs-mule/Makefile"
