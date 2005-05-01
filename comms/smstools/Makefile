# New ports collection makefile for:   	smstools
# Date created:                        	06-11-2004
# Whom:                                	Benny Kjaergaard <bennyk@wax.dk>
#
# $FreeBSD$
#

PORTNAME=	smstools
PORTVERSION=	1.14.8
CATEGORIES=	comms
MASTER_SITES=	http://smstools.meinemullemaus.de/packages/

MAINTAINER=	bennyk@wax.dk
COMMENT=	Tools to handle Short Message Service

LIB_DEPENDS=	mm:${PORTSDIR}/devel/mm

WRKSRC=		${WRKDIR}/smstools
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	echo "${EXAMPLESDIR}"
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/src/smsd_cfg.c \
		${WRKSRC}/install.sub \
		${WRKSRC}/Makefile \
		${WRKSRC}/examples/smsd.conf.easy \
		${WRKSRC}/examples/smsd.conf.full \
		${WRKSRC}/bin/sms
	@${REINPLACE_CMD} -e "s|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g; \
				s|%%DOCSDIR%%|${DOCSDIR}|g" \
		${WRKSRC}/install.sub

.include <bsd.port.mk>
