# New ports collection makefile for:   Exuberant Ctags
# Date created:        4 June 1996
# Whom:                jkoshy
#
# $FreeBSD$
#

PORTNAME=	ctags
PORTVERSION=	5.7
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A feature-filled tagfile generator for vi and emacs clones

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-macro-patterns --with-readlib

MAN1=		exctags.1

SUB_FILES+=	pkg-message

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
