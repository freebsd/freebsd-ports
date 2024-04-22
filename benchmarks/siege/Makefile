PORTNAME=	siege
PORTVERSION=	4.1.6
PORTREVISION=	1
CATEGORIES=	benchmarks www
MASTER_SITES=	http://download.joedog.org/siege/ \
		http://fossies.org/linux/www/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	HTTP regression testing and benchmarking utility
WWW=		https://www.joedog.org/JoeDog/Siege

LICENSE=	GPLv2

USES=		autoreconf libtool perl5 ssl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-shared \
		--sysconfdir=${ETCDIR} \
		--with-ssl=${OPENSSLBASE}
CONFIGURE_ENV=	PERL="${PERL}"

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

pre-configure:
	@${RM} ${WRKSRC}/acinclude.m4
	@${RM} ${WRKSRC}/utils/missing

.include <bsd.port.mk>
