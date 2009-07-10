# New ports collection makefile for:	libvorbis
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	libvorbis
PORTVERSION=	1.2.3
PORTEPOCH=	3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/vorbis/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Audio compression codec library

LIB_DEPENDS=	ogg.6:${PORTSDIR}/audio/libogg

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
CONFIGURE_ARGS=	--with-ogg=${LOCALBASE}
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.if defined(NOPORTDOCS)
MAKE_ENV=	DOC=""
.else
MAKE_ENV=	DOC=doc
.endif

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
