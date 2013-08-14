# Created by: Steve Franks <stevefranks@ieee.org>
# $FreeBSD$

PORTNAME=	lpc21isp
PORTVERSION=	1.85
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ISP programmer tool for flashing NXP & Analog Devices ARM7 CPUs

LICENSE=	LGPL3 # (or later)

NO_WRKSUBDIR=	yes

USE_GMAKE=	yes

PLIST_FILES=	bin/lpc21isp

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC .*=|CC ?=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
