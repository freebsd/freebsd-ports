# New ports collection makefile for:	gomysql
# Date created:				Dec 06, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gomysql
PORTVERSION=	0.2.1
CATEGORIES=	databases
MASTER_SITES=	LOCAL/wen
DISTNAME=	Philio-GoMySQL-${PORTVERSION}-0-g61eeb6a

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A MySQL client library written in Go

WRKSRC=		${WRKDIR}/Philio-GoMySQL-862a45c
PLIST_FILES=	${GO_LIBDIR}/mysql.a

USE_GO=		yes

.include <bsd.port.pre.mk>
.include "../../lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
