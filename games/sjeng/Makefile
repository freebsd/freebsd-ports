# New ports collection makefile for:	sjeng
# Date created:				18 Feb 2006
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	sjeng
PORTVERSION=	11.2
CATEGORIES=	games
MASTER_SITES=	http://sjeng.org/ftp/
DISTNAME=	Sjeng-Free-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chess engine supporting chess variations

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgdbm"

PLIST_FILES=	bin/sjeng

.include <bsd.port.mk>
