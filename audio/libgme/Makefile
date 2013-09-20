# $FreeBSD$

PORTNAME=	libgme
PORTVERSION=	0.5.5
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PROJECTHOST}-${PORTVERSION}
EXTRACT_SUFX=	.tbz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of video game music emulators

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

PROJECTHOST=	game-music-emu
USE_DOS2UNIX=	yes
NO_STAGE=	yes
USE_BZIP2=	yes
USES=		cmake
USE_LDCONFIG=	yes

# XXX: dialog(1) doesn't like ^M in LICENSE_FILE
post-extract:	patch-dos2unix

.include <bsd.port.mk>
