# New ports collection makefile for:	viruskiller
# Date created:				2010-08-16
# Whom:					markand
#
# $FreeBSD$
#

PORTNAME=	viruskiller
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.parallelrealities.co.uk/download/viruskiller/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	markand@malikania.fr
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
