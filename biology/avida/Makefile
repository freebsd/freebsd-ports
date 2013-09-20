# Created by: Jeremy <karlj000@unbc.ca>
# $FreeBSD$

PORTNAME=	avida
PORTVERSION=	2.12.4
DISTVERSIONSUFFIX=	-src
CATEGORIES=	biology
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An auto-adaptive genetic system designed for ALife research

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

USES=		cmake:outsource ncurses

PORTDOCS=	*
PLIST_FILES=	${BIN_FILES:S|^|bin/|} \
		${BIN_FILES:S|^|lib/${PORTNAME}/|} \
		${DATA_FILES:S|^|lib/${PORTNAME}/|}
PLIST_DIRS=	lib/${PORTNAME}

BIN_FILES=	avida avida-viewer
DATA_FILES=	analyze.cfg avida.cfg default-gx.org \
		default-heads-sex.org default-heads.org default-smt.org \
		default-transsmt.org environment.cfg events.cfg \
		experimental.org instset-experimental.cfg instset-gx.cfg \
		instset-heads-sex.cfg instset-heads.cfg instset-smt.cfg \
		instset-transsmt.cfg

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile: invokes i386 asm
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "CMakeLists.txt" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|-O[0-9]|| ; \
		 s| pthread| ${PTHREAD_LIBS}|'
	@${REINPLACE_CMD} -e '/long long int/s|std::abs|llabs|' \
		${WRKSRC}/avida-core/source/main/cPopulationInterface.cc

pre-build:
.for exec in ${BIN_FILES}
	@(cd ${WRKSRC} && ${ECHO_CMD} \
		'cd ${PREFIX}/lib/${PORTNAME} && ./${exec} $$@' > ${exec}.sh)
.endfor

do-install:
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
.for exec in ${BIN_FILES}
	(cd ${WRKSRC} \
		&& ${INSTALL_SCRIPT} ${exec}.sh ${PREFIX}/bin/${exec})
	(cd ${BUILD_WRKSRC}/bin \
		&& ${INSTALL_PROGRAM} ${exec} ${PREFIX}/lib/${PORTNAME})
.endfor
	(cd ${WRKSRC}/avida-core/support/config \
		&& ${INSTALL_DATA} *.cfg ${PREFIX}/lib/${PORTNAME} \
		&& ${INSTALL_DATA} *.org ${PREFIX}/lib/${PORTNAME})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/avida-core/documentation \
		&& ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
