# $FreeBSD$

PORTNAME=	stm32flash
DISTVERSION=	0.5
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flash program for STM32 using the ST serial bootloader

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl-2.0.txt

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/stm32flash \
		share/man/man1/stm32flash.1.gz

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/stm32flash

.include <bsd.port.mk>
