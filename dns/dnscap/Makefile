# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	dnscap
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	dns

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	DNS network traffic capture utility

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS THREADS
OPTIONS_DEFAULT=THREADS

CONFIGURE_ARGS=	--enable-shared --enable-static
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf libtool

GH_ACCOUNT=	DNS-OARC
GH_TUPLE=	DNS-OARC:pcap-thread:v3.1.0:pcap/src/pcap-thread
USE_GITHUB=	yes

THREADS_CONFIGURE_ENABLE=	threads

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^install-data-am: / s| install-dist_docDATA||' ${WRKSRC}/Makefile.am

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e '/^dist_doc_DATA = / s| LICENSE||' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
