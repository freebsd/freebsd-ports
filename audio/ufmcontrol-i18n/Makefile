# Created by: Nicola Vitale <nivit@users.sourceforge.net>
# $FreeBSD$

PORTNAME=		ufmcontrol-i18n
PORTVERSION=		0.3.1
CATEGORIES=		audio
MASTER_SITES=		SF/ufmcontrol/${PORTNAME}/${PORTVERSION}

MAINTAINER=		nivit@FreeBSD.org
COMMENT=		USB radio control utility

RUN_DEPENDS=		snack>=2.2.10_4:${PORTSDIR}/audio/snack

USES=			tcl
USE_LDCONFIG=		yes
NO_STAGE=	yes
MAKE_ENV=		NO_PROFILE=yes

MAN1=			ufmcontrol.1
MANLANG=		"" it.ISO8859-1

.include <bsd.port.mk>
