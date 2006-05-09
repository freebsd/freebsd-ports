# New ports collection makefile for: SWI-Prolog
# Date created:			10 August 1996
# Whom:				Michael Butschky <butsch@computi.erols.com>
#
# $FreeBSD$
#

PORTNAME=	swi-pl
PORTVERSION=	5.6.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.swi.psy.uva.nl/SWI-Prolog/ \
		http://gollem.science.uva.nl/cgi-bin/nph-download/SWI-Prolog/
DISTNAME=	pl-${PORTVERSION}

MAINTAINER=	g.gonter@ieee.org
COMMENT=	Edinburgh-style Prolog compiler

CONFLICTS=	slffea-[0-9]* TenDRA-[0-9]*

NOPRECIOUSMAKEVARS=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--host=${MACHINE_ARCH}-${OPSYS:L} --disable-mt

MAN1=		pl.1 plrc.1 plld.1

PLIST_SUB=	DISTNAME=${DISTNAME} ARCH=${ARCH} OS=${OPSYS:L}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500100
IGNORE=		doesn't support FreeBSD < 5.0. Require some C99 functions
.endif

.if (${ARCH} == "i386")
PLIST_SUB+=	BITS=32
.else
PLIST_SUB+=	BITS=64
.endif

.if (${ARCH} == "alpha")
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src-configure \
		${FILESDIR}/extra-patch-src-Makefile-in
.endif

post-patch:
	${REINPLACE_CMD} -e '/edit/s/INSTALL_PROGRAM/BSD_INSTALL_SCRIPT/g' \
		${WRKSRC}/src/Makefile.in

post-configure:
	${REINPLACE_CMD} -e '/MALLOC_H/s/^#define \(HAVE_.*MALLOC_H\).*/\/\* #undef \1 \*\//g' \
		${WRKSRC}/src/config.h
	${REINPLACE_CMD} -e '/^ARCH=/s/^ARCH=.*/ARCH=${ARCH}-${OPSYS:L}/' \
		${WRKSRC}/src/Makefile

post-install:
.for f in pl plld plrc
	@${STRIP_CMD} ${PREFIX}/lib/${DISTNAME}/bin/${ARCH}-${OPSYS:L}/$f
.endfor
# swi-pl creates this empty directory
	${RMDIR} ${PREFIX}/lib/${DISTNAME}/man

.include <bsd.port.post.mk>
