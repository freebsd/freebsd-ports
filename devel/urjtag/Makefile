# New ports collection makefile for:	urjtag
# Date created:		2008-01-05
# Whom:			Bruce M. Simpson
#
# $FreeBSD$
#

PORTNAME=	urjtag
PORTVERSION=	0.9
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	stevefranks@ieee.org
COMMENT=	Extended utility to work with JTAG-aware boards

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	CFLAGS=--std=c99

MAN1=		jtag.1 bsdl2jtag.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.5)
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
.endif

.include <bsd.port.post.mk>
