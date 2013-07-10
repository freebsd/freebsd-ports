# Created by: markand
# $FreeBSD$

PORTNAME=	viruskiller
PORTVERSION=	1.03
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	FRUGALWARE/games-extra/${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	Arcade game that relies on quick reflexes

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

USE_SDL=	mixer image ttf net
USES=		gmake

BROKEN=		Does not build

INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKEFILE=	makefile

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
BROKEN=	Does not build with new libz
.endif

post-patch:
	# Remove non-free restricted files:
	${RM} -f ${WRKSRC}/music/* ${WRKSRC}/sound/*

.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e "s|^.*install.*DOCS.*||g" \
		-e "s|^.*mkdir.*DOCDIR.*||g" \
		${WRKSRC}/makefile
.endif
	@${REINPLACE_CMD} -e "s|^PREFIX.*|PREFIX=${PREFIX}|g" \
		-e "s|^BINDIR.*|BINDIR=${PREFIX}/bin/|g" \
		-e "s|^DATADIR.*|DATADIR=${DATADIR}/|g" \
		-e "s|^DOCDIR.*|DOCDIR=${DOCSDIR}|g" ${WRKSRC}/makefile

.include <bsd.port.mk>
