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

do-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_DATA} \
		${WRKSRC}/example/dancer.config \
		${WRKSRC}/example/dancer.users \
		${WRKSRC}/example/dancer.funcs \
		${WRKSRC}/example/dancer.explain \
			${PREFIX}/share/${PORTNAME}/

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
LDFLAGS+=	-lm
MAKE_ARGS+=	LDFLAGS="${LDFLAGS}"
.endif

.include <bsd.port.post.mk>
