# Ports collection makefile for:	treepuzzle
# Date created:				26 August 2002
# Whom:					lentferj
#
# $FreeBSD$
#

PORTNAME=	treepuzzle
PORTVERSION=	5.1
CATEGORIES=	biology
MASTER_SITES=	http://www.tree-puzzle.de/
DISTNAME=	tree-puzzle-${PORTVERSION}

MAINTAINER=	jan.lentfer@web.de
COMMENT=	Maximum likelihood phylogeny reconstruction using quartets

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
PLIST_FILES=	bin/puzzle

.include <bsd.port.mk>
