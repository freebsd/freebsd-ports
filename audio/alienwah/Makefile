# New ports collection Makefile for:   alienwah
# Date created:                        13 May 2002
# Whom:                                Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	alienwah
PORTVERSION=	1.13
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://plugin.org.uk/releases/alienwah/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Paul Nasca's AlienWah LADSPA Plugin

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

USE_GMAKE=	yes
USE_LDCONFIG=	yes
PLIST_FILES=	lib/ladspa/aw.so
MAKE_ARGS=	CPP="${CXX}" CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include -fPIC"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Broken with gcc 4.2
.endif

do-install:
	@${INSTALL_DATA} ${WRKSRC}/aw.so ${LOCALBASE}/lib/ladspa

.include <bsd.port.post.mk>
