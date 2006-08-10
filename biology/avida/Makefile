# New ports collection makefile for:	avida
# Date created:		17 April 2002
# Whom:			Jeremy <karlj000@unbc.ca>
#
# $FreeBSD$
#

PORTNAME=	avida
PORTVERSION=	2.4.3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	sf@slappy.org
COMMENT=	Avida is an auto-adaptive genetic system designed for ALife research

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake

CMAKE_ARGS=	-DPROJECT_BINARY_DIR=${WRKSRC}/build/work \
		-DAVD_CONSISTENCY_TEST_PRIMITIVE:BOOL=OFF \
		-DAVD_GUI_NCURSES:BOOL=ON \
		-DAVD_PRIMITIVE:BOOL=ON \
		-DAVD_UNIT_TESTS:BOOL=OFF\
		-DCMAKE_BUILD_TYPE:STRING=Release

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x.
.endif

do-build:
	@(cd ${BUILD_WRKSRC}; \
	${MKDIR} build build/work; \
	cd build; \
	cmake ${CMAKE_ARGS} ..; \
	${MAKE})

do-install:
	@(cd ${BUILD_WRKSRC}; \
	cd build; \
	${MAKE} install)

post-install:
	${MKDIR} ${PREFIX}/share/${PORTNAME}
	(cd ${WRKSRC}/build/work/work; \
	${INSTALL_PROGRAM} AvidaConsole ${PREFIX}/bin; \
	${INSTALL_PROGRAM} task_event_gen ${PREFIX}/bin; \
	${INSTALL_DATA} analyze.cfg environment.cfg events.cfg genesis genesis.4stack inst_set.4stack inst_set.default organism.default ${PREFIX}/share/${PORTNAME} )
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(${CP} -RP ${WRKSRC}/documentation/ ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
