# New ports collection makefile for:	cvschangelogbuilder
# Date created:				Sun Mar  5 16:43:25 EST 2006
# Whom:					Matthew Will <mwill@spingen.com>
#
# $FreeBSD$
#

PORTNAME=	cvschangelogbuilder
PORTVERSION=	2.4
CATEGORIES=	devel
MASTER_SITES=	SF/cvschangelogb/CVSChangelogBuilder/${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Utility to generate changelogs and reports from a CVS repository

RUN_DEPENDS=	${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph

NO_BUILD=	yes
USE_PERL5=	yes

PLIST_FILES=	bin/cvschangelogbuilder
PORTDOCS=	*

post-patch:
	${REINPLACE_CMD} -e '1s|/usr/bin/perl|${PERL}|' ${WRKSRC}/${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/docs/*.* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/images/* ${DOCSDIR}/images
.endif

.include <bsd.port.mk>
