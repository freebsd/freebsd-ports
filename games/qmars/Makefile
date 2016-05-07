# Created by: alepulver
# $FreeBSD$

PORTNAME=	qmars
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://martin.ankerl.com/files/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quicker Mars - heavily optimized mars simulator

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	makedepend:devel/makedepend

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		tar:bzip2
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|g++|$${CXX}| ; \
		s|-O3|$${CXXFLAGS}|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|\./||' ${WRKSRC}/bench.*
	@${REINPLACE_CMD} -e 's|pmars|&-server|' ${WRKSRC}/bench.pmars
	@${REINPLACE_CMD} -e 's|Warrior::||' ${WRKSRC}/warrior.hpp
	@${REINPLACE_CMD} -e 's|Parser::||' ${WRKSRC}/parser.hpp

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} bench.exhaust bench.exmars \
		bench.pmars bench.qmars ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} warriors ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
