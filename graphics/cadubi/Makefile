# Ports collection makefile for:  cadubi
# Date created:			  24 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cadubi
PORTVERSION=	1.3
CATEGORIES=	graphics editors
MASTER_SITES=	http://langworth.com/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ASCII drawing utility

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey

USE_PERL5=	yes
NO_BUILD=	yes

do-configure:
	@${PERL} -pi -e \
		's|Bin/help|Bin/../share/cadubi/help|g' ${WRKSRC}/cadubi

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cadubi ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/help.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/logo.txt ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/extras/ansi_term_codes.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
