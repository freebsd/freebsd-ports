# New ports collection makefile for:	ipcheck
# Date created:		24 Mar 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ipcheck
PORTVERSION=	0.93
CATEGORIES=	net
MASTER_SITES=	http://ipcheck.sourceforge.net/releases/
DISTNAME=	${PORTNAME}.${PORTVERSION:E}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	lioux@FreeBSD.org

USE_PYTHON=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-patch:
	@${SED} -e "s!/usr/bin/python!${LOCALBASE}/bin/python!" \
		-e "s!ppp0!tun0!" \
			${DISTDIR}/${DISTNAME} > ${WRKDIR}/${DISTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}.py

.include <bsd.port.mk>
