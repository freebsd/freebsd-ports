# Created by: Hyper NIKKI System Project <hnsmaster@h14m.org>
# $FreeBSD$

PORTNAME=	hns
PORTVERSION=	2.19.9
CATEGORIES=	japanese www perl5
MASTER_SITES=	SFJP/h14m/22597

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hyper NIKKI System, a CGI system for Electric Diary Interchange

USES=		perl5
NO_BUILD=	yes

PLIST_FILES=	bin/hns-setup bin/todayhns
PORTDATA=	*

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -pR ${WRKSRC}/ ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/hns-setup ${STAGEDIR}${PREFIX}/bin/hns-setup
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/todayhns/todayhns \
		${STAGEDIR}${PREFIX}/bin/todayhns

.include <bsd.port.mk>
