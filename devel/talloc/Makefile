# New ports collection makefile for:	talloc
# Date created:				18 Apr 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		talloc
PORTVERSION=		2.0.1
PORTREVISION=		1
PORTEPOCH=		0
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.samba.org/pub/%SUBDIR%/ \
			ftp://ca.samba.org/pub/%SUBDIR%/ \
			ftp://de.samba.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Hierarchical pool based memory allocator

CONFLICTS=		samba-3.3*

USE_GMAKE=		yes
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
USE_AUTOTOOLS=		autoconf autoheader

IPATHS=			-I${WRKSRC}/libreplace
AUTOHEADER_ARGS=	${IPATHS}
AUTOCONF_ARGS=		${IPATHS}

PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PKGCONFIGDIR_REL?=	${PKGCONFIGDIR:S|^${PREFIX}/||}

CONFIGURE_ENV+=		XSLTPROC="/usr/bin/true"

MAN3=			talloc.3

PLIST_FILES=		include/talloc.h \
			lib/libtalloc.a \
			lib/libtalloc.so \
			lib/libtalloc.so.2 \
			${PKGCONFIGDIR_REL}/talloc.pc

pre-install:
.if !exists(${WRKSRC}/talloc.3)
			@${CP} ${FILESDIR}/talloc.3 ${WRKSRC}
.endif

post-install:
			${LN} -sf libtalloc.so.2 ${PREFIX}/lib/libtalloc.so

.include <bsd.port.mk>
