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

USES=		gmake
USE_GCC=	any
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gnutls

PLIST_FILES=	sbin/bhm sbin/postal bin/postal-list sbin/rabid \
		man/man1/postal-list.1.gz man/man8/bhm.8.gz \
		man/man8/postal.8.gz man/man8/rabid.8.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-O2 -g|| ; \
		 s|-lstdc|$${LDFLAGS}|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
