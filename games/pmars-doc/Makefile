# New ports collection makefile for:	pmars-doc
# Date created:				30 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	pmars
PORTVERSION=	0.9.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	corewar
PKGNAMESUFFIX=	-doc

MAINTAINER=	alejandro@varnet.biz
COMMENT=	The pMARS Documentation (references, warriors, man pages, etc.)

NO_BUILD=	yes

MAN6=		pmars.6

do-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/config
.for f in 94x.opt icws.opt mw.mac pmars.mac x.opt
	@${INSTALL_DATA} ${WRKSRC}/config/${f} ${DOCSDIR}/config
.endfor
	@${MKDIR} ${DOCSDIR}/doc
.for f in corewar-faq.html primer.94 primer.cdb redcode.ref
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}/doc
.endfor
	@${MKDIR} ${DOCSDIR}/warriors
.for f in aeka.red flashpaper.red pspace.red rave.red validate.red
	@${INSTALL_DATA} ${WRKSRC}/warriors/${f} ${DOCSDIR}/warriors
.endfor
	@${INSTALL_MAN} ${WRKSRC}/doc/pmars.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
