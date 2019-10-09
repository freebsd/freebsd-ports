# $FreeBSD$

PORTNAME=	libbind
PORTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	dns net
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
USES=		groff

OPTIONS_DEFINE=	IPV6 THREADS
OPTIONS_DEFAULT=	THREADS

IPV6_CONFIGURE_ENABLE=		ipv6
THREADS_CONFIGURE_ENABLE=	threads

verify:	checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

post-patch:
	${REINPLACE_CMD} -e '/#include <utmp.h>/ d' ${WRKSRC}/irs/*.c

.include <bsd.port.mk>
