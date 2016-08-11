# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	siege
PORTVERSION=	4.0.2
CATEGORIES=	benchmarks www
MASTER_SITES=	http://download.joedog.org/siege/ \
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

pre-configure:
	@${RM} -f ${WRKSRC}/acinclude.m4
	@${RM} -f ${WRKSRC}/utils/missing

.include <bsd.port.mk>
