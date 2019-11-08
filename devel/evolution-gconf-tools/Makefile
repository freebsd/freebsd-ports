# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/evolution-gconf-tools/Makefile,v 1.2 2005/10/14 20:39:56 adamw Exp $

PORTNAME=	evolution-gconf-tools
PORTVERSION=	0.1.6
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	http://people.redhat.com/dmalcolm/evolution-gconf-tools/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Scripts to make it easier to work with Evolution's configuration

RUN_DEPENDS=	evolution:mail/evolution

GNU_CONFIGURE=	yes
USES=		gnome python:2.7
USE_GNOME=	gnomeprefix
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${SH}|' \
		${WRKSRC}/lib/*

post-install:
	@${RMDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/evolution-gconf-tools

.include <bsd.port.mk>
