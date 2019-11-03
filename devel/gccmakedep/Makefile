# Created by: Dave Grochowski
# $FreeBSD$

PORTNAME=	gccmakedep
PORTVERSION=	1.0.3
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Create dependencies in makefiles using 'gcc -M'

USES=		xorg-cat:util

BUILD_DEPENDS=	tradcpp:devel/tradcpp

PLIST_FILES=	bin/gccmakedep man/man1/gccmakedep.1.gz
CONFIGURE_ENV+=	ac_cv_path_RAWCPP=tradcpp

.include <bsd.port.mk>
