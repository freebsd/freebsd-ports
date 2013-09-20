# Created by: jkoshy
# $FreeBSD$

PORTNAME=	ctags
PORTVERSION=	5.8
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	A feature-filled tagfile generator for vi and emacs clones


GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-macro-patterns --with-readlib

MAN1=		exctags.1

SUB_FILES+=	pkg-message

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
