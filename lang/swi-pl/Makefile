# New ports collection makefile for: SWI-Prolog
# Version required:		3.2.9
# Date created:			10 August 1996
# Whom:				Michael Butschky <butsch@computi.erols.com>
#
# $FreeBSD$
#

DISTNAME=	pl-3.2.9
PKGNAME=	swi-pl-3.2.9
CATEGORIES=	lang
MASTER_SITES=	ftp://swi.psy.uva.nl/pub/SWI-Prolog/

MAINTAINER=	max@FreeBSD.org

Y2K=		http://www.hio.hen.nl/faq/SWI-Prolog.html#7.__warranty

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--host=${ARCH}-freebsd
STRIP=
MAKE_FLAGS+=	CIFLAGS=-DRTLD_LAZY -f
MAN1=		pl.1 plrc.1 plld.1
PLIST_SUB=	DISTNAME=${DISTNAME}

post-install:
.for f in pl pl-bite plld plrc
	@strip ${PREFIX}/lib/${DISTNAME}/bin/${PERL_ARCH}/$f
.endfor

.include <bsd.port.mk>
