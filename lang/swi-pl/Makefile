# New ports collection makefile for: SWI-Prolog
# Date created:			10 August 1996
# Whom:				Michael Butschky <butsch@computi.erols.com>
#
# $FreeBSD$
#

PORTNAME=	swi-pl
PORTVERSION=	5.2.8
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.swi.psy.uva.nl/pub/SWI-Prolog/
DISTNAME=	pl-${PORTVERSION}

MAINTAINER=	max@FreeBSD.org
COMMENT=	Edinburgh-style Prolog compiler

CONFLICTS=	ploticus-* slffea-* TenDRA-*
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--host=${MACHINE_ARCH}-${OPSYS:L} --disable-mt
STRIP=
MAN1=		pl.1 plrc.1 plld.1
PLIST_SUB=	DISTNAME=${DISTNAME} ARCH=${ARCH} OS=${OPSYS:L}

post-install:
.for f in pl plld plrc
	@${STRIP_CMD} ${PREFIX}/lib/${DISTNAME}/bin/${ARCH}-${OPSYS:L}/$f
.endfor

.include <bsd.port.mk>
