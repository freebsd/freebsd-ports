# Created by: lx
# $FreeBSD$

PORTNAME=	listener
PORTVERSION=	1.7.2
CATEGORIES=	audio security
MASTER_SITES=	http://www.vanheusden.com/listener/ \
		http://redundancy.redundancy.org/mirror/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@freebsd.org
COMMENT=	Program to listen for and record sound activity

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile

PORTDOCS=	manual.html

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
