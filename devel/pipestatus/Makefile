# Created by: chinsan
# $FreeBSD$

PORTNAME=	pipestatus
PORTVERSION=	0.6.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	UNIX/POSIX shell helper for running pipes safely

NO_BUILD=	yes

PORTDOCS=	ChangeLog README NEWS
PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
