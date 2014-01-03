# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cascade
PORTVERSION=	1.4
CATEGORIES=	cad
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	rfcascade/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A simple tool to analyze noise and distortion of a RF system

GNU_CONFIGURE=	YES
PORTDOCS=	ex1.gif index.html
PORTEXAMPLES=	README.examples ex1.cas ex1.gif ex1.out cascade-mode.el
PLIST_FILES=	bin/cascade

MAN1=		cascade.1

NO_STAGE=	yes

.include <bsd.port.options.mk>

do-install:
		@${INSTALL_SCRIPT} ${WRKSRC}/cascade ${PREFIX}/bin
		@${INSTALL_MAN} ${WRKSRC}/cascade.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
		@${MKDIR} ${EXAMPLESDIR}
		@${INSTALL_DATA} ${WRKSRC}/examples/* \
			${WRKSRC}/cascade-mode.el ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
		@${MKDIR} ${DOCSDIR}
		@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
