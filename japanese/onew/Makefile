# New ports collection makefile for:	ONEW for Wnn4
# Version required:	jvim2.0r+onew2.2.10
# Date created:		5 Sep 1997
# Whom:			Satoshi TAOKA <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id$
#

DISTNAME=	jvim2.0r+onew2.2.10
PKGNAME?=	ja-onew-wnn4-2.2.10
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Japan/onew/ \
		ftp://ftp.leo.chubu.ac.jp/pub/editor/jvim/

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

BUILD_DEPENDS=	${BUILD_INPUT_METHOD}
LIB_DEPENDS=	${LIB_INPUT_METHOD}

PATCHDIR=	${.CURDIR}/../onew-wnn4/patches
FILESDIR=	${.CURDIR}/../onew-wnn4/files
WRKSRC=		${WRKDIR}/onew
# A value 'all' must not be set to TARGET.
ALL_TARGET=	

.if !defined(CANNA) && !defined(WNN4) && !defined(WNN6)
# For this port
WNN4=			yes
.endif
# Specifying a velue INPUT_METHOD, and seting values BUILD_DEPENDS,
# LIB_DEPENDS, etc.
.if defined(CANNA)
INPUT_METHOD+=		canna
LIB_INPUT_METHOD+=	canna\\.1\\.:${PORTSDIR}/japanese/Canna
JPLIB+=			-lcanna
.endif
.if defined(WNN4)
INPUT_METHOD+=		wnn4
BUILD_INPUT_METHOD+=	${LOCALBASE}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
JPDEF+=			-DWNN_ISDIR
JPLIB+=			-ljd -lcrypt
.elif defined(WNN6)
INPUT_METHOD+=		wnn6
BUILD_INPUT_METHOD+=	${LOCALBASE}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
JPDEF+=			-DWNN_ISDIR
JPLIB+=			-ljd -lcrypt
.endif
#
# Make a value of INPUT_METHOD
.if defined(INPUT_METHOD)
INPUT_METHOD!=	echo ${INPUT_METHOD} | sed -e 's/^/-/' -e 's/ /+/g'
.endif
#
ONEW_CONF=	${FILESDIR}/ONEW_CONF-for${INPUT_METHOD}
LIB_NAME=	libonew${INPUT_METHOD}.a
PORT_DOCDIR=	${LOCALBASE}/share/doc/ja-onew${INPUT_METHOD}

post-patch:
	${SED}	-e 's,%LOCALBASE%,${LOCALBASE},g' \
		-e 's,%X11BASE%,${X11BASE},g' \
		${ONEW_CONF} > ${WRKSRC}/ONEW_CONF

do-install:
	${INSTALL_DATA} ${WRKSRC}/libonew.a ${LOCALBASE}/lib/${LIB_NAME}
.if !defined(NOPORTDOCS)
.if defined(PORT_DOCDIR)
	${MKDIR} ${PORT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ONEW ${PORT_DOCDIR}
.endif
.endif
.if defined(WNN6)
	${MKDIR} ${LOCALBASE}/lib/wnn/ja_JP/rk.wnn6
	for file in 1B_TOUPPER 1B_ZENHIRA 1B_ZENKATA 1B_newTOUPPER \
			2A_CTRL 2B_DAKUTEN 2B_JIS 2B_ROMKANA 2_TCODE \
			3B_HANKATA 3B_KATAKANA 3B_ZENKAKU autork \
			mode mode.hankata mode.nohankata; do \
		${INSTALL_DATA} ${LOCALBASE}/lib/wnn/ja_JP/rk/$${file} \
			 ${LOCALBASE}/lib/wnn/ja_JP/rk.wnn6; \
	done
	@${ECHO} "############################################################"
	@${ECHO} "We install all files in ${LOCALBASE}/lib/wnn/ja_JP/rk/"
	@${ECHO} "  into new directory ${LOCALBASE}/lib/wnn/ja_JP/rk.wnn6/"
	@${ECHO} "############################################################"
.endif

.include <bsd.port.mk>
