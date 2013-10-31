# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	when
PORTVERSION=	1.1.22
CATEGORIES=	deskutils
MASTER_SITES=	LOCAL/culot

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Simple personal calendar

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

WRKSRC=		${WRKDIR}/${PORTNAME}_dist

NO_STAGE=	yes
do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
