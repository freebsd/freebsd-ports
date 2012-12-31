# Created by: Vincent Tantardini <vinc@FreeBSD-fr.org>
# $FreeBSD$

PORTNAME=	cuetools
PORTVERSION=	1.3.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of utilities for working with cue files and toc files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		cuebreakpoints.1 cueconvert.1 cueprint.1
PORTDOCS=	README
PORTEXAMPLES=	cuetag.sh
PLIST_FILES=	bin/cuebreakpoints bin/cueconvert bin/cueprint

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/extras/cuetag.sh ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
