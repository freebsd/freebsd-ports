# New ports collection makefile for:	discid 1.3
# Date created:		May 27, 2002
# Whom:			Oliver Breuninger <ob@breuninger.org>
#
# $FreeBSD$

PORTNAME=	discid
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://jeremy.zawodny.com/c/discid/
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Identify audio cd in your drive

WRKSRC=		${WRKDIR}/freebsd

PLIST_FILES=	bin/discid

post-patch:
	@${REINPLACE_CMD} -e 's|^void main|int main|' ${WRKSRC}/${PORTNAME}.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
