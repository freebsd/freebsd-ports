# New ports collection makefile for:	tdb
# Date created:				1 May 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		tdb
PORTVERSION=		1.1.5
PORTREVISION=		0
PORTEPOCH=		0
CATEGORIES=		databases
PKGNAMESUFFIX=

COMMENT=		Trivial Database

CONFLICTS=

SAMBA_PORT?=		samba4-devel
SAMBA_SUBPORT=		yes

MASTERDIR=		${.CURDIR}/../../net/${SAMBA_PORT}
PKGDIR=			${.CURDIR}

WRKSRC=			${WRKDIR}/${DISTNAME}/lib/tdb

USE_PYTHON=		yes
USE_GMAKE=		yes
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
USE_GNOME=		pkgconfig
USE_AUTOTOOLS=		autoconf:262 autoheader:262

PLIST_FILES=		bin/tdbbackup \
			bin/tdbdump \
			bin/tdbtool \
			include/tdb.h \
			lib/libtdb.a \
			lib/libtdb.so \
			lib/libtdb.so.1 \
			libdata/pkgconfig/tdb.pc \
			${PYTHONPREFIX_SITELIBDIR:S|${PREFIX}/||}/tdb.so

post-install:
		@${LN} -sf libtdb.so.1 ${PREFIX}/lib/libtdb.so

.include "${MASTERDIR}/Makefile"
