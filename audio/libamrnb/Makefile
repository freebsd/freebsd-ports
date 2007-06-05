# New ports collection makefile for:	libamrnb
# Date created:	30 May 2007
# Whom:		Tatsuki Makino <tatsuki_makino@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	libamrnb
PORTVERSION=	6.1.0.4
CATEGORIES=	audio
MASTER_SITES=	http://ftp.penguin.cz/pub/users/utx/amr/testing/ \
		http://ftp.penguin.cz/pub/users/utx/amr/
DISTNAME=	amrnb-${DISTVERSION}rc1

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	The floating-point Adaptive Multi Rate speech codec libraries

BUILD_DEPENDS=	wget:${PORTSDIR}/ftp/wget \
		${UNZIP_CMD}:${PORTSDIR}/archivers/unzip \
		bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
WRKSRC=		${WRKDIR}/amrnb-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--srcdir=${WRKSRC}
CONFIGURE_ENV+=	LANG=C
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s!(/bin/bash)!${LOCALBASE}\\1!" \
		${WRKSRC}/prepare_sources.sh

.include <bsd.port.mk>
