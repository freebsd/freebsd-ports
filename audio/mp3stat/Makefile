# ex:ts=8
# Ports collection makefile for:	mp3stat
# Date created:			Mar 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mp3stat
PORTVERSION=	2.5.6
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cronyx.ru/pub/FreeBSD/ports/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read information about mp3s and oggs bitstream

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/mp3stat
USE_GNOME=	gtk12
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"

.if defined(WITH_VORBIS)
LIB_DEPENDS=	vorbis.2:${PORTSDIR}/audio/libvorbis
MAKE_ENV+=	WITH_VORBIS="${WITH_VORBIS}"

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Ogg/Vorbis support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_VORBIS=yes\""
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
