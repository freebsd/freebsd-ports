# New ports collection makefile for:   	smstools
# Date created:                        	06-11-2004
# Whom:                                	Benny Kjaergaard <bennyk@wax.dk>
#
# $FreeBSD$
#

PORTNAME=	smstools
PORTVERSION=	2.0.7
CATEGORIES=	comms
MASTER_SITES=	http://www.meinemullemaus.de/software/smstools/packages/

MAINTAINER=	bennyk@wax.dk
COMMENT=	Tools to handle Short Message Service

LIB_DEPENDS=	mm:${PORTSDIR}/devel/mm

WRKSRC=		${WRKDIR}/smstools
USE_GMAKE=	yes
USE_RC_SUBR=	smsd.sh
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR} \
	EXAMPLESDIR=${EXAMPLESDIR}

post-patch:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/smsd.sh.in > ${WRKDIR}/smsd.sh
	@${REINPLACE_CMD} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/src/smsd_cfg.c \
		${WRKSRC}/install.sh \
		${WRKSRC}/examples/smsd.conf.easy \
		${WRKSRC}/examples/smsd.conf.full

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/smsd.sh ${PREFIX}/etc/rc.d/smsd.sh

.include <bsd.port.mk>
