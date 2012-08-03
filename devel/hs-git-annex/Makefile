# New ports collection makefile for:	git-annex
# Date created:				8 June 2011
# Whom:					frase@frase.id.au
#
# $FreeBSD$
#

PORTNAME=	git-annex
PORTVERSION=	3.20120522
PORTREVISION=	1
CATEGORIES=	devel haskell

MAINTAINER=	frase@frase.id.au
COMMENT=	Manage files with git, without checking their contents into git

LICENSE=	GPLv3
FILE_LICENSE=	GPL

CABAL_SETUP=	Setup.hs

USE_CABAL=	bloomfilter dataenc edit-distance hslogger HTTP IfElse \
		json lifted-base MissingH monad-control mtl network \
		pcre-light QuickCheck>=2.1 SHA text transformers-base \
		utf8-string

USE_GMAKE=		yes
USE_PERL5_BUILD=	yes

BUILD_DEPENDS+=	rsync:${PORTSDIR}/net/rsync \
		git:${PORTSDIR}/devel/git

RUN_DEPENDS+=	rsync:${PORTSDIR}/net/rsync \
		git:${PORTSDIR}/devel/git

EXECUTABLE=	git-annex git-annex-shell
STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
