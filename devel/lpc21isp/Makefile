# Created by: Steve Franks <stevefranks@ieee.org>
# $FreeBSD$

PORTNAME=	lpc21isp
PORTVERSION=	1.97
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ISP programmer tool for flashing NXP & Analog Devices ARM7 CPUs

LICENSE=	LGPL3+

BROKEN_armv6=		fails to compile: no member named 'nQuestionMarks' in 'ISP_ENVIRONMENT'
BROKEN_armv7=		fails to compile: no member named 'nQuestionMarks' in 'ISP_ENVIRONMENT'

USES=		gmake

PLIST_FILES=	bin/lpc21isp

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC .*=|CC ?=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
