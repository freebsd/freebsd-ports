# New ports collection makefile for: SWI-Prolog
# Version required:		2.7.14
# Date created:			10 August 1996
# Whom:				Michael Butschky <butsch@computi.erols.com>
#
# $Id: Makefile,v 1.25 1996/08/10 00:12:11 butsch@computi.erols.com Exp $              
#

DISTNAME=	pl-2.7.14
PKGNAME=	swi-pl-2.7.14
CATEGORIES+=    lang
MASTER_SITES=	ftp://swi.psy.uva.nl/pub/SWI-Prolog/

MAINTAINER=	max@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	i386-freebsd
STRIP=
MAKE_FLAGS+=	CIFLAGS=-DRTLD_LAZY -f
NO_CDROM= 	"No commercial use."

# Below is for broken configure script that comes with the original
# distribution.  This, and patches/patch-00 will be removed as soon as
# the original files are corrected.
pre-configure:
	@${CP} ${FILESDIR}/configure ${WRKSRC}

post-install:
.for f in pl pl-bite chpl
	@strip ${PREFIX}/lib/${DISTNAME}/bin/i386-freebsd/$f
.endfor
.if !defined(NOMANCOMPRESS)
.for f in pl.1 chpl.1 plld.1
	gzip -9nf ${PREFIX}/man/man1/$f
.endfor
.endif

.include <bsd.port.mk>
