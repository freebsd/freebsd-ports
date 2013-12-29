# Created by: db
# $FreeBSD$

PORTNAME=	predict
PORTVERSION=	2.2.3
CATEGORIES=	comms astro hamradio
MASTER_SITES=	ftp://ftp.amsat.org/amsat/software/Linux/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Satellite tracking program for amateur radio satellites

LICENSE=	GPLv2

INSTALL_TARGET=	install install.man

MAKE_ENV=	LIBS="${PTHREAD_LIBS}"

post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/predict.h > ${WRKSRC}/predict.h
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/vocalizer.h > ${WRKSRC}/vocalizer/vocalizer.h
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' -e 's|%%STAGEDIR%%|${STAGEDIR}|g' \
	    ${FILESDIR}/Makefile  > ${WRKSRC}/Makefile

.include <bsd.port.mk>
