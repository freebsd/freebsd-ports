# ports collection makefile for:	MySQL-client
# Version required:			v3.22.x
# Date created:				Thu Jun 24 00:12:22 CEST 1999
# Whom:					Dirk Froemberg <dirk@FreeBSD.org>
#
# $Id: Makefile,v 1.59 1999/07/01 08:44:47 dirk Exp $
#

PKGNAME=	${DISTNAME:S/-/-client-/g}

MASTERDIR=	${.CURDIR}/../mysql322-server
COMMENT=	${PKGDIR}/COMMENT.client
PLIST=		${PKGDIR}/PLIST.client

CLIENT_ONLY=	yes

.include "${MASTERDIR}/Makefile"
