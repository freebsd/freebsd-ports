# ex:ts=8
# New ports collection makefile for:	LeoArg
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	leoarg
PORTVERSION=	2.2.2
CATEGORIES=	devel
MASTER_SITES=	http://home.pages.at/kingleo/development/
DISTNAME=	LeoArg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

MAN3=	LeoArg.3 LeoArg__InvalidOption.3 LeoArg__InvalidSetting.3 \
	LeoArg__Option.3 LeoArg__Setting.3 LeoArg_cpp.3 LeoArg_hh.3 \
	StringUtils_cpp.3 StringUtils_hh.3 namespace_StringUtils.3

.include <bsd.port.mk>
