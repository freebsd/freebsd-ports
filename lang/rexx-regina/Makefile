# ex:ts=8
# Ports collection makefile for:	rexx-regina
# Date created:			Nov 11, 2003
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	regina
PORTVERSION=	3.5
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}-rexx/${PORTNAME}-rexx/${PORTVERSION}
PKGNAMEPREFIX=	rexx-
DISTNAME=	Regina-REXX-${PORTVERSION}

MAINTAINER=	g.gonter@ieee.org
COMMENT=	A Rexx interpreter

CONFLICTS=	rexx-imc-* oorexx-[0-9]*

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes
USE_RC_SUBR=	rxstack

MAN1=	regina.1

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e "s|-xchar=unsigned||g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
