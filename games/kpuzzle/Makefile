# New ports collection makefile for:	kpuzzle
# Date created:				2000-11-04
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		kpuzzle
PORTVERSION=		0.2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	unstable/apps/games

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=2
USE_AUTOCONF=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

pre-configure:
	${PERL} -pi -e "s@default@en@g" ${WRKSRC}/kpuzzle/doc/en/Makefile.in

.include <bsd.port.mk>
