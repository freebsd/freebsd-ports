# New ports collection makefile for:	libvorbis
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	libvorbis
PORTVERSION=	1.0.r3
PORTEPOCH=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.xiph.org/ogg/vorbis/download/ \
		http://www.vorbis.com/files/rc2/unix/ \
		http://www.oddsock.org/vorbisrc3/files/rc3/unix/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	naddy@FreeBSD.org

LIB_DEPENDS=	ogg.3:${PORTSDIR}/audio/libogg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ogg=${LOCALBASE}

.if defined(NOPORTDOCS)
MAKE_ENV=	DOC=""
.else
MAKE_ENV=	DOC=doc
.endif

.include <bsd.port.mk>
