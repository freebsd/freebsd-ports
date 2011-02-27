# New ports collection makefile for:	qmars
# Date created:				2008-01-15
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	qmars
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://corewar.co.uk/ankerl/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quicker Mars is heavily optimized to be as fast as possible

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

USE_BZIP2=	yes
REINPLACE_ARGS=	-i ""
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|g++|${CXX}|; s|CCFLAGS =|& ${CXXFLAGS}|' \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|\./||' ${WRKSRC}/bench.*
	@${REINPLACE_CMD} -e 's|pmars|&-server|' ${WRKSRC}/bench.pmars
	@${REINPLACE_CMD} -e 's|Warrior::||' ${WRKSRC}/warrior.hpp
	@${REINPLACE_CMD} -e 's|Parser::||' ${WRKSRC}/parser.hpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bench.* ${DATADIR}
	${CP} -r ${WRKSRC}/warriors ${DATADIR}

.include <bsd.port.mk>
