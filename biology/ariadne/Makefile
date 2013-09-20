# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	ariadne
PORTVERSION=	1.3
CATEGORIES=	biology
MASTER_SITES=	http://www.well.ox.ac.uk/ariadne/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs to compare protein sequences and profiles

WRKSRC=		${WRKDIR}/SRC-${PORTVERSION}
USE_GMAKE=	yes

PLIST_FILES+=	bin/ariadne bin/prospero
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}| ; \
		s|CC =|CC ?=| ; \
		s|CFLAGS =|CFLAGS +=| ; \
		s|-c $(OPTIMISE)|-c $(CFLAGS) $(OPTIMIZE)|g' ${WRKSRC}/Makefile

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}/ariadne ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}/prospero ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
