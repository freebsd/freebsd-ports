# $FreeBSD$

PORTNAME=	trigger-data
PORTVERSION=	0.6.0
CATEGORIES=	games
MASTER_SITES=	SF/trigger-rally/trigger-rally/trigger-${PORTVERSION}
DISTNAME=	trigger-rally-${PORTVERSION}-data

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Data files for trigger-rally

USES=		tar:bzip2

DATADIR=	${PREFIX}/share/trigger-rally

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
# Avoid conflict with trigger-rally
	@${RM} -f ${STAGEDIR}${DATADIR}/COPYING* \
		${STAGEDIR}${DATADIR}/README*

.include <bsd.port.mk>
