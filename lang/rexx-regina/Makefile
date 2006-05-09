# ex:ts=8
# Ports collection makefile for:	rexx-regina
# Date created:			Nov 11, 2003
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	regina
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}-rexx
PKGNAMEPREFIX=	rexx-
DISTNAME=	Regina-REXX-${PORTVERSION}

MAINTAINER=	g.gonter@ieee.org
COMMENT=	A Rexx interpreter

CONFLICTS=	rexx-imc-* oorexx-[0-9]*

WRKSRC=		${WRKDIR}/Regina-${PORTVERSION}
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	regina.1

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e "s|-xchar=unsigned||g" ${WRKSRC}/Makefile

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/rxstack.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
