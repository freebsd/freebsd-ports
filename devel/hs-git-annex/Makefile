# New ports collection makefile for:	git-annex
# Date created:				8 June 2011
# Whom:					frase@frase.id.au
#
# $FreeBSD$
#

PORTNAME=	git-annex
PORTVERSION=	3.20110702
CATEGORIES=	devel haskell
MASTER_SITES=	http://git.kitenet.net/?p=git-annex.git;a=snapshot;sf=tgz;h=refs/tags/
DISTFILES=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	frase@frase.id.au
COMMENT=	Manage file hierarchies with git

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-MissingH>=0:${PORTSDIR}/devel/hs-MissingH \
		hs-pcre-light>=0:${PORTSDIR}/devel/hs-pcre-light \
		hs-utf8-string>=0:${PORTSDIR}/devel/hs-utf8-string \
		hs-SHA>=0:${PORTSDIR}/security/hs-SHA \
		hs-dataenc>=0:${PORTSDIR}/converters/hs-dataenc \
		hs-curl>0:${PORTSDIR}/ftp/hs-curl \
		git:${PORTSDIR}/devel/git \
		rsync:${PORTSDIR}/net/rsync

RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-MissingH>=0:${PORTSDIR}/devel/hs-MissingH \
		hs-pcre-light>=0:${PORTSDIR}/devel/hs-pcre-light \
		hs-utf8-string>=0:${PORTSDIR}/devel/hs-utf8-string \
		hs-SHA>=0:${PORTSDIR}/security/hs-SHA \
		hs-dataenc>=0:${PORTSDIR}/converters/hs-dataenc \
		hs-curl>0:${PORTSDIR}/ftp/hs-curl \
		git:${PORTSDIR}/devel/git \
		rsync:${PORTSDIR}/net/rsync

USE_PERL5=	yes
USE_GMAKE=	yes

MAN1=		git-annex.1 \
		git-annex-shell.1 \
		git-union-merge.1

LICENSE=	GPLv3

PLIST_FILES=	bin/git-annex \
		bin/git-annex-shell \
		bin/git-union-merge

.include	<bsd.port.mk>
