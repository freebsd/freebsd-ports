# ex:ts=8
# Ports collection makefile for:	mp3stat
# Date created:			Mar 20, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mp3stat
PORTVERSION=	2.5.11
CATEGORIES=	audio
MASTER_SITES=	https://signal-lost.homeip.net/files/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read information about mp3s and oggs bitstream

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk20
USE_GMAKE=	yes
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"

PORTDOCS=	README
PLIST_FILES=	bin/mp3stat

OPTIONS=	VORBIS "Ogg/Vorbis support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_VORBIS)
MAKE_ARGS+=	VORBIS=""
.else
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
CXXFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3stat ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
