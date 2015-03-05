# $FreeBSD$

PORTNAME=	libbind
PORTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	dns net ipv6
MASTER_SITES=	ISC/libbind/${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standard C resolver library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --with-randomdev=/dev/random

OPTIONS_DEFINE=	IPV6 THREADS
OPTIONS_DEFAULT=	IPV6 THREADS

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

verify:	checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

.if ${OSVERSION} > 900007
post-patch:
	${REINPLACE_CMD} -e '/#include <utmp.h>/ d' ${WRKSRC}/irs/*.c
.endif

.include <bsd.port.post.mk>
