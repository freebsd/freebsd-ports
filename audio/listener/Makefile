# Created by: lx
# $FreeBSD$

PORTNAME=	listener
PORTVERSION=	2.2
CATEGORIES=	audio security
MASTER_SITES=	PACKETSTORM/linux/security \
		http://www.vanheusden.com/listener/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to listen for and record sound activity

LICENSE=	GPLv2

BUILD_DEPENDS=	portaudio2>0:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile
RUN_DEPENDS=	portaudio2>0:${PORTSDIR}/audio/portaudio2

USES=		ncurses tar:tgz

CPPFLAGS+=	-I${LOCALBASE}/include/portaudio2 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/portaudio2 -L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|-g |$$(CPPFLAGS) | ; \
		 s|-O2 || ; \
		 s|-ldl |$$(LDFLAGS) |' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} listener setlistener \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_DATA} listener.conf \
		${STAGEDIR}${PREFIX}/etc/listener.conf.sample)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} manual.html \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
