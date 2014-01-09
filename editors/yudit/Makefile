# Created by: rch@richard.eu.org
# $FreeBSD$

PORTNAME=	yudit
PORTVERSION=	2.9.2
CATEGORIES=	editors converters print
MASTER_SITES=	http://yudit.org/download/ \
		SUNSITE/apps/editors/X

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-lingual Unicode text editor with TTF support

CONFLICTS=	netatalk-[0-9]*

USE_XORG=	x11
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LC_ALL=
MAKE_ENV=	LC_ALL=
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
