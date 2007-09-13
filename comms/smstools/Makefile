# New ports collection makefile for:   	smstools
# Date created:                        	06-11-2004
# Whom:                                	Benny Kjaergaard <bennyk@wax.dk>
#
# $FreeBSD$
#

PORTNAME=	smstools
PORTVERSION=	2.2.18
CATEGORIES=	comms
MASTER_SITES=	http://www.meinemullemaus.de/software/smstools/packages/

MAINTAINER=	bennyk@wax.dk
COMMENT=	Tools to handle Short Message Service

LIB_DEPENDS=	mm:${PORTSDIR}/devel/mm

BROKEN=		Size/checksum mismatch

WRKSRC=		${WRKDIR}/smstools
USE_GMAKE=	yes
USE_RC_SUBR=	smsd.sh

post-patch:
	@${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/src/smsd_cfg.c \
		${WRKSRC}/install.sh \
		${WRKSRC}/examples/smsd.conf.easy \
		${WRKSRC}/examples/smsd.conf.full

.include <bsd.port.mk>
