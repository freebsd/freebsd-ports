# ports collection makefile for:	MySQL-client
# Date created:				Sun Sep 24 21:21:20 CEST 2000
# Whom:					Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${MASTERPORTNAME:S/-server/-client/g}

MASTERDIR=	${.CURDIR}/../mysql323-server
COMMENT=	${PKGDIR}/pkg-comment.client
PKGINSTALL=	mustnotexist
PLIST=		${PKGDIR}/pkg-plist.client

CLIENT_ONLY=	yes

.include "${MASTERDIR}/Makefile"
