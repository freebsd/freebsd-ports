# New ports collection makefile for:	libopensync
# Date created:		2005-06-19
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libopensync
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.opensync.org/attachment/wiki/download/
DISTNAME=	libopensync-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2\?rev=\&format=raw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PIM data synchronization framework

CONFLICTS=	libopensync-0.22*

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_BZIP2=	yes
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
USE_SCONS=	yes
SCONS_ARGS=	prefix=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e 's|$$libsuffix/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|gthread-2.0|gthread-2.0 pthread|' ${WRKSRC}/opensync/SConscript

post-install:
	@${LN} -sf ${LOCALBASE}/lib/libopensync.so ${LOCALBASE}/lib/libopensync.so.1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
