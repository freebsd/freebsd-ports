# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	siege
PORTVERSION=	3.0.8
CATEGORIES=	benchmarks www
MASTER_SITES=	http://www.joedog.org/pub/siege/ \
		http://fossies.org/linux/www/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	HTTP regression testing and benchmarking utility

LICENSE=	GPLv2

USES=		perl5
USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
AUTOMAKE_ARGS=	--add-missing --copy
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
