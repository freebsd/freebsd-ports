# New ports collection makefile for:	libvorbis
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	libvorbis
PORTVERSION=	1.0
PORTREVISION=	1
PORTEPOCH=	3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.wiles.org/pub/mirrors/Vorbis/unix/ \
		http://www.oddsock.org/vorbis/unix/ \
		http://www.casterclub.com/vorbis/unix/ \
		http://www.math.utoledo.edu/~chaese/Vorbis/unix/

MAINTAINER=	naddy@FreeBSD.org

LIB_DEPENDS=	ogg.4:${PORTSDIR}/audio/libogg

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-ogg=${LOCALBASE}
INSTALLS_SHLIB=	yes

.if defined(NOPORTDOCS)
MAKE_ENV=	DOC=""
.else
MAKE_ENV=	DOC=doc
.endif

.include <bsd.port.mk>
