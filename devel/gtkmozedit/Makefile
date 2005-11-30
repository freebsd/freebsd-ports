# New ports collection makefile for:	gtkmozedit
# Date created:		2005-10-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkmozedit
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	devel editors www
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text editor widget based on Mozilla's editing functionality

USE_BZIP2=	yes
USE_REINPLACE=	yes
WITH_MOZILLA?=	firefox
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack
USE_GECKO=	firefox mozilla

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"

post-patch:
	@${REINPLACE_CMD} -e 's|firefox-nspr|firefox-xpcom|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
