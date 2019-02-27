# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imake
PORTVERSION=	1.0.7
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Imake and other utilities from X.Org

LICENSE=	MIT
LICENSE_FILE= ${WRKSRC}/COPYING

BUILD_DEPENDS=	tradcpp:devel/tradcpp
RUN_DEPENDS=	gccmakedep:devel/gccmakedep \
		makedepend:devel/makedepend \
		${LOCALBASE}/lib/X11/config/xorg.cf:x11/xorg-cf-files

USES=	shebangfix perl5 pkgconfig
USE_PERL5=	run

SHEBANG_FILES=	mkhtmlindex.pl

XORG_CAT=	util
USE_XORG=	xorgproto

CONFIGURE_ENV=	ac_cv_path_RAWCPP=tradcpp

.include <bsd.port.mk>
