# New ports collection makefile for:	dancer
# Date created:		02/01/2003
# Whom:			Dominic Marks <dom@cus.org.uk>
#
# $FreeBSD$
#

PORTNAME=	dancer
PORTVERSION=	4.16
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC bot written in C for UNIX, Windows, and AmigaOS

PATCH_WRKSRC=		${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
MAKE_ARGS+=	CSPECIAL="${CFLAGS}" LDFLAGS="${LDFLAGS}"
LDFLAGS+=	-lm
CPP=		#

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/../${PORTNAME} ${PREFIX}/bin/
	cd ${WRKSRC}/../example && ${INSTALL_DATA} \
		dancer.config dancer.users \
		dancer.funcs dancer.explain ${DATADIR}

.include <bsd.port.mk>
