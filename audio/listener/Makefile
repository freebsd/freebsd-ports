# Created by: lx
# $FreeBSD$

PORTNAME=	listener
PORTVERSION=	1.7.2
CATEGORIES=	audio security
MASTER_SITES=	http://www.vanheusden.com/listener/ \
		http://redundancy.redundancy.org/mirror/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A program to listen for and record sound activity

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile

NO_STAGE=	yes
PORTDOCS=	manual.html
PLIST_FILES=	bin/setlistener bin/listener bin/listenersoundpipe \
		etc/listener.conf.sample

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
