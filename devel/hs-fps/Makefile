# ex:ts=8
# New ports collection makefile for:   	hs-fps
# Date created:                        	23 May 2006
# Whom:                                 Maxime Henrion <mux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fps
PORTVERSION=	0.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cse.unsw.edu.au/pub/users/dons/fps/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mux
PKGNAMEPREFIX=	hs-

MAINTAINER=	mux@FreeBSD.org
COMMENT=	Fast, packed, strict byte arrays for Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

OPTIONS=	PROFILE "Build libraries for profiling" off

.include <bsd.port.pre.mk>

SETUP=		Setup.hs

.if defined(WITH_PROFILE)
PLIST_SUB+=	PROFILE=""
PROFILE=	-p
.else
PLIST_SUB+=	PROFILE="@comment "
.endif

PLIST_SUB+=	FPS_VERSION=${PORTVERSION}

do-configure:
	@${CHMOD} +x ${WRKSRC}/${SETUP}
	@cd ${WRKSRC}; ./${SETUP} configure ${PROFILE} --prefix=${LOCALBASE}

do-build:
	@cd ${WRKSRC}; ./${SETUP} build

do-install:
	@cd ${WRKSRC}; ./${SETUP} install

post-install:
	@ver=`ghc -V | ${SED} "s/^.*version \(.*\)$$/\1/"`; \
	    ${REINPLACE_CMD} -e "s|%%GHC_VERSION%%|$${ver}|g" ${TMPPLIST}

.include <bsd.port.post.mk>
