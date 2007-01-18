# New ports collection makefile for:	udis86
# Date created:				7 June 2006
# Whom:					Lutz Boehne <lboehne@damogran.de>
#
# $FreeBSD$
#

PORTNAME=	udis86
PORTVERSION=	1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lboehne@damogran.de
COMMENT=	Minimalistic x86 and x86-64 disassembler library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.if !defined(NOPORTDOCS)
DOCS=	doc.html index.html ss.jpg style.css
.endif

post-configure:
	${REINPLACE_CMD} -e 's,	$$(INSTALL_PROGRAM),	$$(INSTALL_DATA),' ${WRKSRC}/libudis86/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
