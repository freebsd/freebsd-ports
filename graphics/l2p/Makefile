# New ports collection makefile for:	l2p
# Date created:		2006-03-22
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	l2p
PORTVERSION=	1.1.1
#PORTREVISION=	0
CATEGORIES=	graphics print perl5
MASTER_SITES=	http://www.redsymbol.net/software/l2p/dist/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Create PNG images from LaTeX math expressions

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		latex:${PORTSDIR}/print/teTeX

USE_PERL5_RUN=	yes
USE_ZIP=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/l2p
PORTDOCS=	l2p.txt l2p.html

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PERL} -w|' ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
