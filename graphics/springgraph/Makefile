# ex:ts=8
# Ports collection makefile for:	springgraph
# Date created:			Aug 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	springgraph
PORTVERSION=	0.79
CATEGORIES=	graphics
MASTER_SITES=	http://www.chaosreigns.com/code/springgraph/dl/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.pl

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD

USE_PERL5=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e "s|/usr/bin/perl|${PERL}|g" ${WRKSRC}/springgraph.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/springgraph.pl ${PREFIX}/bin/springgraph

.include <bsd.port.mk>
