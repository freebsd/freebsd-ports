# Created by: Douglas K. Rand <rand@meridian-enviro.com>
# $FreeBSD$

PORTNAME=	libirman
PORTVERSION=	0.5.2
CATEGORIES=	comms
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ndowens@yahoo.com
COMMENT=	Library for Evation's Irman infrared receiver

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool pkgconfig pathfix

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

DOCS=	AUTHORS ChangeLog README TECHNICAL TODO

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
