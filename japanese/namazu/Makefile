# Created by: Seiichirou Hiraoka
# $FreeBSD$

PORTNAME=	namazu
PORTVERSION=	1.3.0.11
CATEGORIES=	japanese textproc
MASTER_SITES=	http://www.namazu.org/stable/ \
		LOCAL/flathill

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Search engine software intended for easy use

BUILD_DEPENDS=	kakasi:${PORTSDIR}/japanese/kakasi \
		nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS=	kakasi:${PORTSDIR}/japanese/kakasi \
		nkf:${PORTSDIR}/japanese/nkf

USES=		perl5
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

post-patch:
	@${REINPLACE_CMD} '/^int main/ s|uchar|char|' ${WRKSRC}/namazu.c

.include <bsd.port.mk>
