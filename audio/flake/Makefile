# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flake
PORTVERSION=	0.11
CATEGORIES=	audio
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME:L}-enc/${PORTNAME:L}/${PORTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	FLAC audio encoder

LICENSE=	LGPL21

CONFIGURE_ARGS+=	--cc="${CC}"
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gmake
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/flake include/flake.h lib/libflake.a

.include <bsd.port.mk>
