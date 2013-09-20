# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	phoon
PORTVERSION=	2005
CATEGORIES=	astro
MASTER_SITES=	http://www.acme.com/software/phoon/
PKGNAMESUFFIX=	_29jun
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}${PORTVERSION}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Displays the phase of the moon

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		BINDIR=${LOCALBASE}/bin \
		MANDIR=${MANPREFIX}/man/man1

NO_STAGE=	yes
MAN1=		phoon.1
PLIST_FILES=	bin/phoon

pre-patch:
	@${REINPLACE_CMD} -e 's|gmtoff = !!!;||g' \
		${WRKSRC}/date_parse.c

.include <bsd.port.mk>
