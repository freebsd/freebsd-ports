# New ports collection Makefile for: ja-ng-canna
# Date created:		11 January 1999
# Whom:				HONDA Yasuhiro <honda@kashio.info.mie-u.ac.jp>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-canna

MASTERDIR=	${.CURDIR}/../ng
DESCR=		${.CURDIR}/pkg-descr

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna

MAINTAINER=	honda@kashio.info.mie-u.ac.jp
COMMENT=	A very lightweight Emacs-clone with Japanese and Canna support

.include "${MASTERDIR}/Makefile"

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include -DCANNA" \
		LIBS="-L${LOCALBASE}/lib -lcanna -ltermcap"
