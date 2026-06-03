PORTNAME=	imake
DISTVERSION=	1.0.11
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Obsolete C preprocessor interface to the make utility
WWW=		https://gitlab.freedesktop.org/xorg/util/imake

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	gccmakedep:devel/gccmakedep \
		makedepend:devel/makedepend \
		${LOCALBASE}/lib/X11/config/xorg.cf:x11/xorg-cf-files

USES=		shebangfix tar:xz perl5 pkgconfig xorg xorg-cat:util
USE_XORG=	xorgproto
USE_PERL5=	run

SHEBANG_FILES=	mkhtmlindex.pl

.include <bsd.port.mk>
