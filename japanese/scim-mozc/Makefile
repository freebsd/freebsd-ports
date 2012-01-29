# New ports collection makefile for:	scim-mozc
# Date created:				26 June 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PKGNAMEPREFIX=  ja-scim-
PKGNAMESUFFIX=
COMMENT=	Mozc engine for SCIM
DATADIR=	${PREFIX}/share/scim-${PORTNAME}

MASTERDIR=	${.CURDIR}/../../japanese/mozc-server
PKGMESSAGE=	${.CURDIR}/pkg-message

BUILD_MOZC_LIST=	scim_mozc

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include "${MASTERDIR}/Makefile"
