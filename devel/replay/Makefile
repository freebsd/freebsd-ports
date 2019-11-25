# Created by: alfred@FreeBSD.org
# $FreeBSD$

PORTNAME=	devel-replay
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~alfred/sources/replay/
DISTNAME=	replay-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program that helps you fix a build interactively

USES=		tar:bzip2 uidfix
MAKE_ENV=	WITHOUT_MAN=yes NO_WERROR="defined"

PLIST_FILES=	bin/replay

.include <bsd.port.mk>
