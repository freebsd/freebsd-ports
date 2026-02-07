PORTNAME=	gsimplecal
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.2
CATEGORIES=	deskutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Lightweight calendar applet written in C++ using GTK
WWW=		https://github.com/dmedvinsky/gsimplecal

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lang gmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dmedvinsky
USE_GNOME=	glib20 gtk30

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gsimplecal \
		share/man/man1/gsimplecal.1.gz

.include <bsd.port.mk>
