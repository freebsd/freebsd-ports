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

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|g++|$${CXX}| ; \
		s|-O3|$${CXXFLAGS}|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|\./||' ${WRKSRC}/bench.*
	@${REINPLACE_CMD} -e 's|pmars|&-server|' ${WRKSRC}/bench.pmars
	@${REINPLACE_CMD} -e 's|Warrior::||' ${WRKSRC}/warrior.hpp
	@${REINPLACE_CMD} -e 's|Parser::||' ${WRKSRC}/parser.hpp

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin)
	@${MKDIR} ${DATADIR}
.for i in bench.exhaust bench.exmars bench.pmars bench.qmars
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${i} ${DATADIR})
.endfor
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} warriors ${DATADIR})

.include <bsd.port.mk>
