# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nmealib
PORTVERSION=	0.5.3
CATEGORIES=	comms
MASTER_SITES=	SF/nmea/NmeaLib/nmea-0.5.x

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Library for working with the NMEA protocol

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake zip

INCLUDES=	config.h context.h generate.h generator.h gmath.h info.h nmea.h \
		parse.h parser.h sentence.h time.h tok.h units.h

MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libnmea.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/nmea
.for i in ${INCLUDES}
	${INSTALL_DATA} ${WRKSRC}/include/nmea/${i} ${STAGEDIR}${PREFIX}/include/nmea
.endfor

.include <bsd.port.mk>
