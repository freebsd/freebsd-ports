# Created by: markand
# $FreeBSD$

PORTNAME=	viruskiller
PORTVERSION=	1.03
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	FRUGALWARE/games-extra/${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An arcade game that relies on quick reflexes

LICENSE=	GPLv2

USE_SDL=	mixer image ttf net
USE_GMAKE=	yes

INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKEFILE=	makefile

post-patch:
	# Remove non-free restricted files:
	${RM} -f ${WRKSRC}/music/* ${WRKSRC}/sound/*

.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|^.*install.*DOCS.*||g" \
		-e "s|^.*mkdir.*DOCDIR.*||g" \
		${WRKSRC}/makefile
.endif
	@${REINPLACE_CMD} -e "s|^PREFIX.*|PREFIX=${PREFIX}|g" \
		-e "s|^BINDIR.*|BINDIR=${PREFIX}/bin/|g" \
		-e "s|^DATADIR.*|DATADIR=${DATADIR}/|g" \
		-e "s|^DOCDIR.*|DOCDIR=${DOCSDIR}|g" ${WRKSRC}/makefile

.include <bsd.port.mk>
