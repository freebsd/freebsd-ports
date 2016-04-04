# Created by: lx
# $FreeBSD$

PORTNAME=	listener
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	audio security
MASTER_SITES=	PACKETSTORM/linux/security \
		http://www.vanheusden.com/listener/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to listen for and record sound activity

LICENSE=	GPLv2

LIB_DEPENDS=	libportaudio.so:audio/portaudio \
		libsndfile.so:audio/libsndfile

USES=		localbase ncurses tar:tgz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|-g |$$(CPPFLAGS) | ; \
		 s|-O2 || ; \
		 s|-ldl |$$(LDFLAGS) |' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/listener ${WRKSRC}/setlistener \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/listener.conf \
		${STAGEDIR}${PREFIX}/etc/listener.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} manual.html \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
