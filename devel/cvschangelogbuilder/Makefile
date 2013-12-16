# Created by: Matthew Will <mwill@spingen.com>
# $FreeBSD$

PORTNAME=	cvschangelogbuilder
PORTVERSION=	2.5
CATEGORIES=	devel
MASTER_SITES=	SF/cvschangelogb/CVSChangelogBuilder/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to generate changelogs and reports from a CVS repository

LICENSE=	GPLv2

RUN_DEPENDS=	p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph

NO_BUILD=	yes
USES=		perl5

PLIST_FILES=	bin/cvschangelogbuilder
PORTDOCS=	*

NO_STAGE=	yes
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
