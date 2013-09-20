# Created by: dlowe
# $FreeBSD$

PORTNAME=	xmake
PORTVERSION=	1.06
CATEGORIES=	devel
MASTER_SITES=	http://apollo.backplane.com/xmake/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A powerful make utility

WRKSRC=		${WRKDIR}/xmake
MAN1=		xmake.1
PLIST_FILES=	bin/xmake

NO_STAGE=	yes
pre-build:
	@${RM} -rf ${WRKSRC}/obj

.include <bsd.port.mk>
