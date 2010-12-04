# New ports collection makefile for:	tdb
# Date created:				1 May 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		tdb
PORTVERSION=		1.2.1
PORTREVISION=		1
PORTEPOCH=		1
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.samba.org/pub/%SUBDIR%/ \
			ftp://ca.samba.org/pub/%SUBDIR%/ \
			ftp://de.samba.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Trivial Database

CONFLICTS=		*samba3[0-4]-3.*

USE_PYTHON=		yes
USE_GMAKE=		yes
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
USE_GNOME=		pkgconfig
USE_AUTOTOOLS=		autoconf autoheader

LICENSE=		GPLv3
MAKE_JOBS_SAFE=		yes

IPATHS=			-I${WRKSRC}/libreplace
AUTOHEADER_ARGS=	${IPATHS}
AUTOCONF_ARGS=		${IPATHS}
PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PKGCONFIGDIR_REL?=	${PKGCONFIGDIR:S|^${PREFIX}/||}
PYTHON_SITELIBDIR_REL?=	${PYTHONPREFIX_SITELIBDIR:S|^${PREFIX}/||}

CONFIGURE_ENV+=		XSLTPROC="/usr/bin/true"

MAN8=			tdbbackup.8 \
			tdbdump.8 \
			tdbtool.8

PLIST_FILES=		bin/tdbbackup \
			bin/tdbdump \
			bin/tdbtool \
			include/tdb.h \
			lib/libtdb.a \
			lib/libtdb.so \
			lib/libtdb.so.1 \
			${PKGCONFIGDIR_REL}/tdb.pc \
			${PYTHON_SITELIBDIR_REL}/tdb.so

pre-install:
.for man in ${MAN8}
			@${INSTALL_MAN} ${FILESDIR}/${man} ${WRKSRC}/manpages
.endfor

.include <bsd.port.mk>
