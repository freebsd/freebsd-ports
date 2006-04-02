# New ports collection makefile for:	glom
# Date created:				24 April, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/glom/Makefile,v 1.4 2005/07/01 17:55:37 marcus Exp $
#

PORTNAME=	glom
PORTVERSION=	0.8.30
PORTREVISION=	1
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.8

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME database designed

LIB_DEPENDS=	bakery-2.4:${PORTSDIR}/x11-toolkits/bakery \
		gdamm-1.3:${PORTSDIR}/databases/libgdamm
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PYTHON=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix pygnomeextras
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INSTALLS_OMF=	yes

BROKEN=	needs an update to 1.0

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 500000)
BROKEN=		"Doesn't play well with 4.X."
.endif

.include <bsd.port.post.mk>
