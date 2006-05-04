# ex:ts=8
# Ports collection makefile for:	openzz
# Date created:			May 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	openzz
PORTVERSION=	1.0.4.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interpreted dynamic parser

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s/cfree/free/g" ${WRKSRC}/src/list.c
.if ${OSVERSION} <= 500027
	@${FIND} ${WRKSRC}/src -type f | ${XARGS} ${REINPLACE_CMD} \
		-e 's|<stdint.h>|<inttypes.h>|'
.endif

.include <bsd.port.post.mk>
