# ex:ts=8
# Ports collection makefile for:	sedsed
# Date created:			Jan 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sedsed
PORTVERSION=	0.6
CATEGORIES=	devel
MASTER_SITES=	http://sedsed.sourceforge.net/
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
USE_PYTHON=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sedsed-0.6 ${PREFIX}/bin/sedsed

.include <bsd.port.mk>
