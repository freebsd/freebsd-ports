# New ports collection makefile for:	tevent
# Date created:				1 May 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		tevent
PORTVERSION?=		0.9.6
PORTREVISION=		0
PORTEPOCH=		0
CATEGORIES=		devel
PKGNAMESUFFIX=

COMMENT=		Talloc based event loop library

LIB_DEPENDS=		talloc.1:${PORTSDIR}/devel/talloc

CONFLICTS=

SAMBA_PORT?=		samba4-devel
SAMBA_SUBPORT=		yes

MASTERDIR=		${.CURDIR}/../../net/${SAMBA_PORT}
PKGDIR=			${.CURDIR}

WRKSRC=			${WRKDIR}/${DISTNAME}/lib/tevent

USE_GMAKE=		yes
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
USE_GNOME=		pkgconfig
USE_AUTOTOOLS=		autoconf:262 autoheader:262

PLIST_FILES=		include/tevent.h \
			include/tevent_internal.h \
			lib/libtevent.a \
			lib/libtevent.so \
			lib/libtevent.so.0 \
			libdata/pkgconfig/tevent.pc

post-install:
		${LN} -sf libtevent.so.0 ${PREFIX}/lib/libtevent.so

.include "${MASTERDIR}/Makefile"
