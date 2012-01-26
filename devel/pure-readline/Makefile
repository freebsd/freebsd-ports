# New ports collection makefile for:	pure-readline
# Date created:		2011-10-21
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-readline
PORTVERSION=	0.1
CATEGORIES=	devel

MAINTAINER=	lichray@gmail.com
COMMENT=	A readline interface for the Pure language

USE_PURE=	yes
NO_PURE_EXAMPLES=	yes

PLIST_FILES=	lib/pure/readline.pure \
		lib/pure/readline.so

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/pure/bsd.pure.mk"
.include <bsd.port.post.mk>
