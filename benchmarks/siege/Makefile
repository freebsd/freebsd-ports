PORTNAME=	siege
PORTVERSION=	4.1.3
CATEGORIES=	benchmarks www
MASTER_SITES=	http://download.joedog.org/siege/ \
		http://fossies.org/linux/www/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	HTTP regression testing and benchmarking utility

LICENSE=	GPLv2

USES=		autoreconf libtool perl5 ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-shared \
		--sysconfdir=${ETCDIR} \
		--with-ssl=${OPENSSLBASE}
CONFIGURE_ENV=	PERL="${PERL}"

pre-configure:
	@${RM} ${WRKSRC}/acinclude.m4
	@${RM} ${WRKSRC}/utils/missing

.include <bsd.port.mk>
