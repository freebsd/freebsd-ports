# ex:ts=8
# New ports collection makefile for:	utf8conv
# Date created:			Jul 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	utf8conv
PORTVERSION=	1.0.1
CATEGORIES=	converters
MASTER_SITES=	http://www.fibrespeed.net/~mbabcock/code/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-1.0
ALL_TARGET=	${PORTNAME}

post-patch:
	@${PERL} -pi -e "s,^CC,#CC,g ; \
		s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/utf8conv ${PREFIX}/bin

.include <bsd.port.mk>
