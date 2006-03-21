# New ports collection makefile for:	listener
# Date created:			2004-11-24
# Whom:				lx
#
# $FreeBSD$
#

PORTNAME=	listener
PORTVERSION=	1.7.2
CATEGORIES=	audio security
MASTER_SITES=	http://www.vanheusden.com/listener/ \
		http://redundancy.redundancy.org/mirror/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A program to listen for and record sound activity

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile

PORTDOCS=	manual.html
PLIST_FILES=	bin/setlistener bin/listener bin/listenersoundpipe \
		etc/listener.conf.sample

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
