# New ports collection makefile for:    ez-ipupdate
# Date created:         24 July 2002
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	ez-ipupdate
PORTVERSION=	3.0.11b8
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	http://dyn.pl/client/UNIX/ez-ipupdate/ \
		http://www.yi.org/help/software/ \
		http://www.devil-linux.us/pub/devel/sources/1.3/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Update your host name on any dynamic DNS service

USE_RC_SUBR=	ez-ipupdate
GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	for f in ${WRKSRC}/example-*.conf; \
	do \
		${INSTALL_DATA} $$f ${PREFIX}/share/examples/${PORTNAME}/; \
	done
	${INSTALL_DATA} ${WRKSRC}/example.conf \
			${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
