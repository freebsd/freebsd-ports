# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	postal
PORTVERSION=	0.72
CATEGORIES=	benchmarks mail
MASTER_SITES=	http://www.coker.com.au/postal/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Benchmark SMTP/POP servers

LICENSE=	GPLv3

OPTIONS_DEFINE=	SSL
OPTIONS_DEFAULT=	SSL

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USES=		gmake

PLIST_FILES=	sbin/bhm sbin/postal bin/postal-list sbin/rabid

MAN1=	postal-list.1
MAN8=	bhm.8 postal.8 rabid.8

.include <bsd.port.options.mk>

CONFIGURE_ARGS=	--disable-gnutls

.if empty(PORT_OPTIONS:MSSL)
CONFIGURE_ARGS+=	--disable-openssl
.endif

CFLAGS+=	${PTHREAD_CFLAGS} -Wno-long-long
LDFLAGS+=	${PTHREAD_LIBS}

.include <bsd.port.mk>
