# ex:ts=8
# Ports collection makefile for:	rexx-regina
# Date created:			Nov 11, 2003
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	regina
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}-rexx
PKGNAMEPREFIX=	rexx-
DISTNAME=	Regina-REXX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Rexx interpreter

CONFLICTS=	rexx-imc-*

WRKSRC=		${WRKDIR}/Regina-${PORTVERSION}
USE_REINPLACE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	regina.1

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/rxstack.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
