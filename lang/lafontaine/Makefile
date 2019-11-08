# Created by: ijliao
# $FreeBSD$

PORTNAME=	lafontaine
PORTVERSION=	0.4.1
PORTREVISION=	9
CATEGORIES=	lang
MASTER_SITES=	http://www.nongnu.org/lafontaine/archives/
DISTNAME=	${PORTNAME}_0.4-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical logo interpreter

WRKSRC=		${WRKDIR}/${PORTNAME}-0.4

USES=		gmake gnome pathfix pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
LDFLAGS+=	-lm

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

.include <bsd.port.mk>
