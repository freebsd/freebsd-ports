# New ports collection makefile for:	ONEW for FreeWnn
# Date created:		5 Sep 1997
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	onew
PORTVERSION?=	2.2.10
PKGNAMESUFFIX=	${INPUT_METHOD}
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Japan/onew/ \
		ftp://ftp.leo.chubu.ac.jp/pub/editor/jvim/
DISTNAME=	jvim2.0r+${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	A library for a Japanese Input Method: FreeWnn

WRKSRC=		${WRKDIR}/${PORTNAME}
# A value 'all' must not be set to TARGET.
ALL_TARGET=	

.if !defined(CANNA) && !defined(FREEWNN) && !defined(WNN6) && !defined(WNN7)
# For this port
FREEWNN=	yes
.endif
# Specifying a velue INPUT_METHOD, and seting values BUILD_DEPENDS,
# LIB_DEPENDS, etc.
.if defined(CANNA)
INPUT_METHOD+=	canna
LIB_DEPENDS+=	canna.1:${PORTSDIR}/japanese/Canna
JPLIB+=		-lcanna
.endif
.if defined(FREEWNN)
INPUT_METHOD+=	freewnn
BUILD_DEPENDS+=	${LOCALBASE}/lib/libjd.a:${PORTSDIR}/japanese/FreeWnn-lib
JPLIB+=		-ljd -lcrypt
JPDEF+=		-DWNN_ISDIR
.elif defined(WNN6)
INPUT_METHOD+=	wnn6
BUILD_DEPENDS+=	${LOCALBASE}/lib/libjd.a:${PORTSDIR}/japanese/FreeWnn-lib
JPLIB+=		-ljd -lcrypt
JPDEF+=		-DWNN_ISDIR
RK_DIR=		${LOCALBASE}/lib/wnn/ja_JP/rk.wnn6
.elif defined(WNN7)
INPUT_METHOD+=	wnn7
BUILD_DEPENDS+=	${LOCALBASE}/lib/libjd.a:${PORTSDIR}/japanese/FreeWnn-lib
JPLIB+=		-ljd -lcrypt
JPDEF+=		-DWNN_ISDIR
RK_DIR=		${LOCALBASE}/lib/wnn/ja_JP/rk.wnn7
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
.if defined(WNN6) || defined(WNN7)
	${MKDIR} ${RK_DIR}
	for file in 1B_TOUPPER 1B_ZENHIRA 1B_ZENKATA 1B_newTOUPPER \
			2A_CTRL 2B_DAKUTEN 2B_JIS 2B_ROMKANA 2_TCODE \
			3B_HANKATA 3B_KATAKANA 3B_ZENKAKU autork \
			mode mode.hankata mode.nohankata; do \
		${INSTALL_DATA} ${LOCALBASE}/lib/wnn/ja_JP/rk/$${file} \
			 ${RK_DIR}; \
	done
	@${ECHO} "############################################################"
	@${ECHO} "We install all files in ${LOCALBASE}/lib/wnn/ja_JP/rk/"
	@${ECHO} "  into a new directory ${RK_DIR}"
	@${ECHO} "############################################################"
.endif

.include <bsd.port.mk>
