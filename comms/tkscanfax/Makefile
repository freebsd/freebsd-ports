# New ports collection makefile for:	tkscanfax
# Date created:			11 Mai 2002
# Whom:				MITA Yoshio <mita@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkscanfax
PORTVERSION=	1.02
CATEGORIES=	comms
MASTER_SITES=	http://shino.pos.to/linux/

MAINTAINER=	mita@FreeBSD.org

RUN_DEPENDS=	wish8.0jp:${PORTSDIR}/japanese/tk80

WRKSRC=	${WRKDIR}/${PORTNAME}
NO_BUILD=	YES

post-extract:
	find ${WRKSRC} -name '*~' -delete

do-install:
	(\
	cd ${WRKDIR}; \
	${TAR} '--exclude=*.orig' -cf - tkscanfax | \
	${TAR} -C ${PREFIX}/lib -xf - ; \
	${LN} -sf ${PREFIX}/lib/tkscanfax/tkscan ${PREFIX}/bin ; \
	${LN} -sf ${PREFIX}/lib/tkscanfax/tkfax ${PREFIX}/bin \
	)

.include <bsd.port.mk>
