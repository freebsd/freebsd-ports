# New ports collection makefile for:	oggsplit
# Date created:			29 Dec 2004
# Whom:				Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	oggsplit
PORTVERSION=	0.1.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://homepage.ntlworld.com/jfe1205/OggVorbis/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Split multiplexed (grouped or chained) Ogg files into separate streams

LIB_DEPENDS=	ogg.7:${PORTSDIR}/audio/libogg

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:15 autoconf:262
AUTOMAKE_ARGS=	--add-missing

MAN1=		oggsplit.1
PLIST_FILES=	bin/oggsplit

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL})

.include <bsd.port.mk>
