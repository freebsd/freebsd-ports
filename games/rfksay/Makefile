# ex:ts=8
# Ports collection makefile for:  rfksay
# Date created:                   Thu Jul 18, 2002
# Whom:                           Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	rfksay
PORTVERSION=	0.1
CATEGORIES=	games
MASTER_SITES=	http://freebsdcluster.org/~mich/software/
DISTNAME=	rfksay

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Generates a kitten finding robot with a text bubble

USE_PERL5=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/kittensay ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/robotsay ${PREFIX}/bin/

.include <bsd.port.mk>
