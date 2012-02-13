# New ports collection makefile for:	git-annex
# Date created:				8 June 2011
# Whom:					frase@frase.id.au
#
# $FreeBSD$
#

PORTNAME=	git-annex
PORTVERSION=	3.20110707
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	frase@frase.id.au
COMMENT=	Manage files with git, without checking their contents into git

LICENSE=	GPLv3
FILE_LICENSE=	GPL

USE_CABAL=	dataenc hS3 hslogger HTTP MissingH mtl network pcre-light \
		SHA utf8-string
CABAL_SETUP=	Setup.hs

USE_GMAKE=		yes
USE_PERL5_BUILD=	yes

BUILD_DEPENDS+=	rsync:${PORTSDIR}/net/rsync \
		git:${PORTSDIR}/devel/git

RUN_DEPENDS+=	rsync:${PORTSDIR}/net/rsync \
		git:${PORTSDIR}/devel/git

EXECUTABLE=	git-union-merge git-annex-shell git-annex
STANDALONE=	yes

MAN1SRC=	.
MAN1=		git-union-merge.1 git-annex-shell.1 git-annex.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
