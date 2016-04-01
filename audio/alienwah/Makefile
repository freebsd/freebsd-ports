# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	alienwah
PORTVERSION=	1.13
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://plugin.org.uk/releases/alienwah/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Paul Nasca's AlienWah LADSPA plugin

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa

USES=		gmake
MAKE_ARGS=	CPP="${CXX}" CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include -fPIC"

PLIST_FILES=	lib/ladspa/aw.so

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ladspa
	${INSTALL_LIB} ${WRKSRC}/aw.so ${STAGEDIR}${PREFIX}/lib/ladspa

.include <bsd.port.mk>
