# New ports collection makefile for:	libamrwb
# Date created:	7 Jun 2007
# Whom:		Tatsuki Makino <tatsuki_makino@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	libamrwb
PORTVERSION=	7.0.0.1
CATEGORIES=	audio
MASTER_SITES=	http://ftp.penguin.cz/pub/users/utx/amr/
DISTNAME=	amrwb-${DISTVERSION}

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Adaptive Multi-Rate - Wideband (AMR-WB) Speech Codec

BUILD_DEPENDS=	wget:${PORTSDIR}/ftp/wget \
		${UNZIP_CMD}:${PORTSDIR}/archivers/unzip \
		bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LANG=C
USE_LDCONFIG=	yes
RESTRICTED=	See Important legal notice of http://www.penguin.cz/~utx/amr.en.html

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s!(/bin/bash)!${LOCALBASE}\\1!" \
		${WRKSRC}/prepare_sources.sh

.include <bsd.port.mk>
