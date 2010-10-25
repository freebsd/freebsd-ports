# New ports collection makefile for:	tdb
# Date created:				1 May 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		tdb
PORTVERSION=		1.2.1
PORTREVISION=		0
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.samba.org/pub/%SUBDIR%/ \
			ftp://ca.samba.org/pub/%SUBDIR%/ \
			ftp://de.samba.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Trivial Database

CONFLICTS=		*samba-3.*

USE_PYTHON=		yes
USE_GMAKE=		yes
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
USE_GNOME=		pkgconfig
USE_AUTOTOOLS=		autoconf:268 autoheader:268

IPATHS=			-I${WRKSRC}/libreplace
AUTOHEADER_ARGS=	${IPATHS}
AUTOCONF_ARGS=		${IPATHS}

PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PKGCONFIGDIR_REL?=	${PKGCONFIGDIR:S|^${PREFIX}/||}
PYTHON_SITELIBDIR_REL?=	${PYTHONPREFIX_SITELIBDIR:S|^${PREFIX}/||}

PLIST_FILES=		bin/tdbbackup \
			bin/tdbdump \
			bin/tdbtool \
			include/tdb.h \
			lib/libtdb.a \
			lib/libtdb.so \
			lib/libtdb.so.1 \
			${PKGCONFIGDIR_REL}/tdb.pc \
			${PYTHON_SITELIBDIR_REL}/tdb.so

post-install:
			@${LN} -sf libtdb.so.1 ${PREFIX}/lib/libtdb.so

.include <bsd.port.mk>
