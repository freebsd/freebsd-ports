# ex:ts=8
# New ports collection makefile for:	postal
# Date created:			Apr 2, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	postal
PORTVERSION=	0.70
CATEGORIES=	benchmarks mail
MASTER_SITES=	http://www.coker.com.au/postal/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Benchmark SMTP/POP servers

OPTIONS=	SSL "Build with OpenSSL support" on

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	sbin/bhm sbin/postal bin/postal-list sbin/rabid

MAN1=	postal-list.1
MAN8=	bhm.8 postal.8 rabid.8

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--disable-gnutls

.if !defined(WITH_SSL)
CONFIGURE_ARGS+=	--disable-openssl
.endif

CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.post.mk>
