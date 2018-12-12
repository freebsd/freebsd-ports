# Created by: Masanori OZAWA (ozawa@ongs.co.jp)
# $FreeBSD$

PORTNAME=	fusenshi
PORTVERSION=	0.9.0
PORTREVISION=	18
CATEGORIES=	deskutils
MASTER_SITES=	http://www.ongs.co.jp/projects/fusenshi/

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	Post-it(R) like application with network support

USES=		compiler:c++11-lang gettext pkgconfig tar:tgz
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm24 gtksourceview libxml2
USE_XORG=	x11
MAKE_JOBS_UNSAFE=	yes
CXXFLAGS+=	-D_WANT_SEMUN

.ifdef WITHOUT_SSL
MAKE_ARGS+=	WITHOUT_SSL=yes
.else
LIB_DEPENDS+=	libgnutls.so:security/gnutls
.endif

BROKEN_aarch64=		Fails to compile: error: cast from pointer to smaller type loses information

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fusenshi

.include <bsd.port.mk>
