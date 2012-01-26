# New ports collection makefile for:	pure-sql3
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-gen
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	lichray@gmail.com
COMMENT=	A C interface generator for the Pure language

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-language-c>=0.3.2:${PORTSDIR}/devel/hs-language-c

USE_PURE=	yes

MAN1=		pure-gen.1

CC= 		gcc

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/pure/bsd.pure.mk"
.include <bsd.port.post.mk>
