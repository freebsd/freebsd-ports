# New ports collection makefile for:	ktranslator
# Date created:		23 May 1998
# Whom:			Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $FreeBSD$
#

PORTNAME=	ktranslator
PORTVERSION=	0.6.1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	Attic/old/1.1.2/apps/utils

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_KDELIBS_VER=1
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
CONFIGURE_ENV=	QTDIR="${X11BASE}" KDEDIR="${LOCALBASE}"
CONFIGURE_ARGS=	--with-extra-includes=${LOCALBASE}/include

post-patch:
	@cd ${WRKSRC} && aclocal

.include <bsd.port.mk>
