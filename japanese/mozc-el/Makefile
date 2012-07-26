# New ports collection makefile for:	mozc-el
# Date created:				26 June 2010
# Whom:					TAKANO, Yuji
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-el-${EMACS_PORT_NAME}
COMMENT=	Mozc for GNU Emacs

MASTERDIR=	${.CURDIR}/../../japanese/mozc-server
PKGMESSAGE=	${.CURDIR}/pkg-message

BUILD_MOZC_LIST=	mozc_el

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include "${MASTERDIR}/Makefile"
