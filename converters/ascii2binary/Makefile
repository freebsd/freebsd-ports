# New ports collection makefile for:	ascii2binary
# Date created:		Sun 29 January 2006
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	ascii2binary
PORTVERSION=	2.13
PORTREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://billposer.org/Software/Downloads/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Convert between textual representations of numbers and binary

USE_BZIP2=	yes
USE_GETTEXT=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/ascii2binary bin/binary2ascii

MAN1=		ascii2binary.1 binary2ascii.1

pre-configure:
	${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
