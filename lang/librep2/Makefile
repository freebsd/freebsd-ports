# New ports collection makefile for:   librep
# Date created:        13 September 1999
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librep
PORTVERSION=	0.11.3
CATEGORIES=	lang
MASTER_SITES=	ftp://librep.sourceforge.net/pub/librep/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm \
		intl.1:${PORTSDIR}/devel/gettext

PLIST_SUB=	GNUHOST=${ARCH}--freebsd${OSREL} VERSION=${PORTVERSION}

USE_NEWGCC=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lxpg4 -lintl"

.include <bsd.port.mk>
