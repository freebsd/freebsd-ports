# $FreeBSD$

PORTNAME=	gsimplecal
PORTVERSION=	2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Lightweight calendar applet written in C++ using GTK

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	dmedvinsky

GNU_CONFIGURE=	yes

USES=		autoreconf gmake pkgconfig
USE_GNOME=	glib20 gtk30

PLIST_FILES=	bin/gsimplecal \
		man/man1/gsimplecal.1.gz

.include <bsd.port.mk>
