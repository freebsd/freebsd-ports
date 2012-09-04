# New ports collection makefile for:	git-annex
# Date created:				8 June 2011
# Whom:					frase@frase.id.au
#
# $FreeBSD$
#

PORTNAME=	git-annex
PORTVERSION=	3.20120807
CATEGORIES=	devel haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Manage files with git, without checking their contents into git

LICENSE=	GPLv3
FILE_LICENSE=	GPL

CABAL_SETUP=	Setup.hs

USE_CABAL=	bloomfilter dataenc edit-distance hslogger HTTP IfElse json \
		lifted-base MissingH monad-control mtl network pcre-light \
		QuickCheck>=2.1 SHA text transformers-base utf8-string

USE_GMAKE=		yes
USE_PERL5_BUILD=	yes

BUILD_DEPENDS+=	rsync:${PORTSDIR}/net/rsync \
		git:${PORTSDIR}/devel/git

RUN_DEPENDS+=	rsync:${PORTSDIR}/net/rsync \
		git:${PORTSDIR}/devel/git

EXECUTABLE=	git-annex git-annex-shell
STANDALONE=	yes

OPTIONS_DEFINE=		S3 ASSISTANT
OPTIONS_DEFAULT=	S3 ASSISTANT

S3_DESC=		S3 support
ASSISTANT_DESC=		'assistant' and 'watch' commands

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MS3}
CONFIGURE_ARGS+=	--flags="S3"
USE_CABAL+=		hS3
.else
CONFIGURE_ARGS+=	--flags="-S3"
.endif

.if ${PORT_OPTIONS:MASSISTANT}
CONFIGURE_ARGS+=	--flags="Assistant"
USE_CABAL+=		stm>=2.3
.else
CONFIGURE_ARGS+=	--flags="-Assistant"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
