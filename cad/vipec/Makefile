# ex:ts=8
# New ports collection makefile for:	vipec
# Date created:			Aprll 3, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vipec
PORTVERSION=	3.0.3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

BUILD_DEPENDS=	tmake:${PORTSDIR}/devel/tmake

USE_QT2=	yes
USE_GMAKE=	yes
MAKE_ENV+=	TMAKEPATH="${LOCALBASE}/share/tmake/freebsd-g++" \
		QTDIR="${X11BASE}" MOC="${X11BASE}/bin/moc2"

.include <bsd.port.mk>
