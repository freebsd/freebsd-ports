# New ports collection makefile for:   librep
# Version required:    0.11.1
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	librep-0.11.1
CATEGORIES=	lang
MASTER_SITES=	ftp://librep.sourceforge.net/pub/librep/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm \
		intl.1:${PORTSDIR}/devel/gettext

VERSION=	0.11.1
PLIST_SUB=	GNUHOST=${ARCH}--freebsd${OSREL} VERSION=${VERSION}

USE_NEWGCC=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lxpg4 -lintl"

.include <bsd.port.mk>
