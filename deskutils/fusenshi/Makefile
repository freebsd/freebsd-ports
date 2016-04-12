# Created by: Masanori OZAWA (ozawa@ongs.co.jp)
# $FreeBSD$

PORTNAME=	fusenshi
PORTVERSION=	0.9.0
PORTREVISION=	14
CATEGORIES=	deskutils
MASTER_SITES=	http://www.ongs.co.jp/projects/fusenshi/

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	Post-it(R) like application with network support

USES=		gettext pkgconfig tar:tgz
USE_GNOME=	gtkmm24 gtksourceview libxml2
USE_XORG=	x11
MAKE_JOBS_UNSAFE=	yes

.ifdef WITHOUT_SSL
MAKE_ARGS+=	WITHOUT_SSL=yes
.else
LIB_DEPENDS+=	libgnutls.so:security/gnutls
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fusenshi

.include <bsd.port.mk>
