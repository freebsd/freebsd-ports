# ex:ts=8
# Ports collection makefile for:	openzz
# Date created:			May 13, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	openzz
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -pi -e "s/cfree/free/g" ${WRKSRC}/src/list.c
.if ${OSVERSION} <= 500027
	@${FIND} ${WRKSRC}/src -type f | ${XARGS} ${PERL} -pi \
		-e 's|<stdint.h>|<inttypes.h>|'
.endif

.include <bsd.port.post.mk>
