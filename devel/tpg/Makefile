# ex:ts=8
# Ports collection makefile for:	tpg
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tpg
PORTVERSION=	0.1.9
CATEGORIES=	devel python
MASTER_SITES=	http://christophe.delord.free.fr/soft/tpg/
DISTNAME=	${PORTNAME:U}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/TPG.py ${PREFIX}/bin/tpg

.include <bsd.port.mk>
