# New ports collection makefile for:	ifm
# Date created:				Mon Oct 12 12:32:07 EDT 1998
# Whom:					Dave Chapeskie <dchapes@ddm.on.ca>
#
# $FreeBSD$
#

PORTNAME=	ifm
PORTVERSION=	5.2
PORTREVISION=	2
CATEGORIES=	games tk
MASTER_SITES=	http://www.ibiblio.org/pub/docs/interactive-fiction/mapping-tools/

MAINTAINER=	akosela@andykosela.com
COMMENT=	Interactive Fiction mapper and walkthrough generator

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

USE_GZIP=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WISH=${LOCALBASE}/bin/wish8.4

post-patch:
	@${REINPLACE_CMD} -e 's|lib doc progs|lib progs|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ifm.pdf ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/ifm/* ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
