# Created by: ache
# $FreeBSD$

PORTNAME=	patch
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU/patch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU patch utility

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--program-prefix=g
USE_XZ=		yes
USES=		charsetfix gmake

PLIST_FILES=	bin/gpatch \
		man/man1/gpatch.1.gz

.include <bsd.port.mk>
