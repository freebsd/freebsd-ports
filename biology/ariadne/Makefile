# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	ariadne
PORTVERSION=	1.3
CATEGORIES=	biology
MASTER_SITES=	http://www.well.ox.ac.uk/ariadne/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs to compare protein sequences and profiles

WRKSRC=		${WRKDIR}/SRC-${PORTVERSION}

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06

PLIST_FILES+=	bin/ariadne bin/prospero
USES=		gmake tar:Z
PORTDOCS=	README
MAKE_ARGS+=	CC="${CC}"

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS =|CFLAGS +=| ; \
		s|-c $$(OPTIMISE)|-c ${CFLAGS} ${OPTIMIZE}|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}/ariadne ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}/prospero ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
