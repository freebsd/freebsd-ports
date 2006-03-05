# New ports collection makefile for:	ascii2binary
# Date created:		Sun 29 January 2006
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	ascii2binary
PORTVERSION=	2.9
CATEGORIES=	converters
MASTER_SITES=	http://billposer.org/Software/Downloads/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Convert between textual representations of numbers and binary

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/ascii2binary bin/binary2ascii

MAN1=		ascii2binary.1 binary2ascii.1

pre-configure:
	${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
