# New ports collection makefile for:   jmode
# Date created:        26 February 2002
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jmode
PORTVERSION=	0.4.29
CATEGORIES=	japanese
MASTER_SITES=	http://www.kmc.gr.jp/proj/heke/

MAINTAINER=	nakai@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/anthy.h:${PORTSDIR}/japanese/anthy

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
