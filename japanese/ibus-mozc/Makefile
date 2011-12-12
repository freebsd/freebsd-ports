# New ports collection makefile for:	ibus-mozc
# Date created:				22 May 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	ja-ibus-
COMMENT=	Mozc engine for IBus
DATADIR=	${PREFIX}/share/ibus-${PORTNAME}

MASTERDIR=      ${.CURDIR}/../../japanese/mozc-server
PKGMESSAGE=	${.CURDIR}/pkg-message

BUILD_MOZC_LIST=        ibus_mozc

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include "${MASTERDIR}/Makefile"
