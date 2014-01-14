# Created by: ache
# $FreeBSD$

PORTNAME=	patch
PORTVERSION=	2.7.1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU patch utility

LICENSE=	GPLv3

USE_XZ=		yes
USES=		charsetfix gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g --disable-silent-rules

PLIST_FILES=	bin/gpatch man/man1/gpatch.1.gz

.include <bsd.port.mk>
