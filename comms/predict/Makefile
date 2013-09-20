# Created by: db
# $FreeBSD$

PORTNAME=	predict
PORTVERSION=	2.2.3
CATEGORIES=	comms astro hamradio
MASTER_SITES=	ftp://ftp.amsat.org/amsat/software/Linux/

MAINTAINER=	db@FreeBSD.org
COMMENT=	Satellite tracking program for amateur radio satellites

INSTALL_TARGET=	install install.man

MAN1=		predict.1
MAKE_ENV=	LIBS="${PTHREAD_LIBS}"

NO_STAGE=	yes
post-patch:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/predict.h > ${WRKSRC}/predict.h
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/vocalizer.h > ${WRKSRC}/vocalizer/vocalizer.h
	${CP} ${FILESDIR}/Makefile  ${WRKSRC}

.include <bsd.port.mk>
