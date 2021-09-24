# Created by: David Naylor <dbn@FreeBSD.org>

PORTNAME=	flake
PORTVERSION=	0.11
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME:tl}-enc/${PORTNAME:tl}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FLAC audio encoder

LICENSE=	LGPL21

DEPRECATED=	Abandoned upstream, no new release since 2007
EXPIRATION_DATE=2021-12-31

CONFIGURE_ARGS+=	--cc="${CC}"
HAS_CONFIGURE=	yes
USES=		gmake tar:bzip2
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/flake include/flake.h lib/libflake.a

.include <bsd.port.mk>
