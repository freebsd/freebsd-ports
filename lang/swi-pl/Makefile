# New ports collection makefile for: SWI-Prolog
# Date created:			10 August 1996
# Whom:				Michael Butschky <butsch@computi.erols.com>
#
# $FreeBSD$
#

PORTNAME=	swi-pl
PORTVERSION=	3.4.4
CATEGORIES=	lang
MASTER_SITES=	ftp://swi.psy.uva.nl/pub/SWI-Prolog/
DISTNAME=	pl-${PORTVERSION}

MAINTAINER=	max@FreeBSD.org

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--host=${ARCH}-${OS}
STRIP=
MAKE_FLAGS+=	CIFLAGS=-DRTLD_LAZY -f
MAN1=		pl.1 plrc.1 plld.1
PLIST_SUB=	DISTNAME=${DISTNAME} ARCH=${ARCH} OS=${OS}

OS!=	uname -s | tr '[:upper:]' '[:lower:]'

post-install:
.for f in pl plld plrc
	@/usr/bin/strip ${PREFIX}/lib/${DISTNAME}/bin/${ARCH}-${OS}/$f
.endfor

.include <bsd.port.mk>
