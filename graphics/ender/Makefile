# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ender
PORTVERSION=	20121003
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://files.roorback.net/e17/extra/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Ender provide common API for enesim renderers

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_BISON=	build
USE_EFL=	eina enesim libtool_hack
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-static

post-patch:
	@${REINPLACE_CMD} -e "s|@LEX@|${LOCALBASE}/bin/flex|" \
		${WRKSRC}/src/lib/Makefile.in

.include <bsd.port.mk>
