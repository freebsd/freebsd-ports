# New ports collection makefile for:	dancer
# Date created:		02/01/2003
# Whom:			Dominic Marks <dom@cus.org.uk>
#
# $FreeBSD$
#

PORTNAME=	dancer
PORTVERSION=	4.16
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An IRC bot written in C for UNIX, Windows, and AmigaOS

PATCH_WRKSRC=		${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
MAKE_ARGS+=	CSPECIAL="${CFLAGS}" LDFLAGS="${LDFLAGS}"

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../${PORTNAME} ${PREFIX}/bin/
	cd ${WRKSRC}/../example && ${INSTALL_DATA} \
		dancer.config dancer.users \
		dancer.funcs dancer.explain ${DATADIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
LDFLAGS+=	-lm
.endif

.include <bsd.port.post.mk>
