# Created by: Evgueni V. Gavrilov <aquatique@rusunix.org>
# $FreeBSD$

PORTNAME=	silc-toolkit
PORTVERSION=	1.1.12
PORTREVISION=	1
CATEGORIES=	devel net security
MASTER_SITES=	SF/silc/silc/toolkit/sources
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure Internet Live Conferencing (SILC) network toolkit

CONFLICTS=	silc-client-1.1.* silc-irssi-client-1.1.*

USES=		gmake libtool pathfix perl5 tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-etcdir=${ETCDIR} \
		--with-simdir=${PREFIX}/lib/silcsim \
		--with-helpdir=${DATADIR}/help \
		--includedir=${PREFIX}/include/silc \
		--enable-shared
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	IPV6 THREADS OPTIMIZED_CFLAGS DOCS
OPTIONS_DEFINE_i386=	OPTIMIZED_ASM
OPTIONS_DEFAULT_i386=	OPTIMIZED_ASM
OPTIONS_DEFAULT=	THREADS OPTIMIZED_CFLAGS

THREADS_CONFIGURE_WITH=	pthreads
IPV6_CONFIGURE_ENABLE=	ipv6
OPTIMIZED_ASM_CONFIGURE_ENABLE=	asm

post-configure:
	@${REINPLACE_CMD} 's|-fno-regmove||' ${WRKSRC}/lib/silccrypt/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/silcsim/*.so

.include <bsd.port.mk>
