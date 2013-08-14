# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	adms
PORTVERSION=	2.3.0
PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	SF/mot-${PORTNAME}/${PORTNAME}-source/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A model generator for SPICE simulators

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig
USE_GNOME=	glib20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		admsXml.1

.include <bsd.port.mk>
