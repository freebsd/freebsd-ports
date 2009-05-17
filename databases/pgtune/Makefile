# New ports collection makefile for:   pgtune
# Date created:        16 feb 2009
# Whom:                Matthieu BOUTHORS
#
# $FreeBSD$
#

PORTNAME=	pgtune
PORTVERSION=	0.9.0
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2068/ \
		http://mirror.labs.fr/pub/FreeBSD/distfiles/

MAINTAINER=	matthieu@labs.fr
COMMENT=	Postgresql.conf tuning tips based on hardware and load type

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgtune  ${PREFIX}/bin/pgtune
	${MKDIR} ${PREFIX}/share/pgtune/settings/
	${CP} ${WRKSRC}/pg_settings* ${PREFIX}/share/pgtune/settings/

.include <bsd.port.mk>
