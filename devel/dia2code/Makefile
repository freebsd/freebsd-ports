# ex:ts=8
# New ports collection makefile for:	dia2code
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dia2code
PORTVERSION=	0.8.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small utility used to generate code from a Dia diagram

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

XML_CONFIG=	${LOCALBASE}/bin/xml2-config

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		XML_CONFIG="${XML_CONFIG}"

MAN1=		dia2code.1
PLIST_FILES=	bin/dia2code

post-patch:
	@${REINPLACE_CMD} -e 's|#include <malloc.h>||' ${WRKSRC}/dia2code/dia2code.h

post-install:
	@${INSTALL_MAN} ${WRKSRC}/dia2code.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
