# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	siege
PORTVERSION=	3.0.9
CATEGORIES=	benchmarks www
MASTER_SITES=	http://www.joedog.org/pub/siege/ \
		http://fossies.org/linux/www/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	HTTP regression testing and benchmarking utility

LICENSE=	GPLv2

USES=		autoreconf libtool perl5
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL="${PERL}"
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE} --disable-shared \
		--sysconfdir=${ETCDIR}

post-patch:
	@${REINPLACE_CMD} -e \
		's|^\(AC_PROG_SHELL\)|dnl \1|' ${WRKSRC}/configure.ac

pre-configure:
	@${RM} -f ${WRKSRC}/acinclude.m4
	@${RM} -f ${WRKSRC}/utils/missing

.include <bsd.port.mk>
