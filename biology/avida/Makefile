# Created by: Jeremy <karlj000@unbc.ca>
# $FreeBSD$

PORTNAME=	avida
PORTVERSION=	2.12.4
DISTVERSIONSUFFIX=	-src
CATEGORIES=	biology
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Auto-adaptive genetic system designed for ALife research

LICENSE=	GPLv3

BROKEN_aarch64=		invokes x86 asm
BROKEN_armv6=		invokes x86 asm
BROKEN_armv7=		invokes x86 asm
BROKEN_mips=		invokes x86 asm
BROKEN_mips64=		invokes x86 asm
BROKEN_sparc64=		missing atomics implementation
BROKEN_powerpc64=	fails to compile: sibling call optimization does not allow automatic multiple TOCs

USES=		cmake:outsource ncurses
CMAKE_ARGS=	-DAPTO_UNIT_TESTS:BOOL=OFF \
		-DAVD_UNIT_TESTS:BOOL=OFF \
		-DNCURSES_INCLUDE_PATH:STRING="${NCURSESINC}"

PORTDOCS=	*
PLIST_FILES=	${BIN_FILES:S|^|bin/|} \
		${BIN_FILES:S|^|lib/${PORTNAME}/|} \
		${DATA_FILES:S|^|lib/${PORTNAME}/|}

BIN_FILES=	avida avida-viewer
DATA_FILES=	analyze.cfg avida.cfg default-gx.org \
		default-heads-sex.org default-heads.org default-smt.org \
		default-transsmt.org environment.cfg events.cfg \
		experimental.org instset-experimental.cfg instset-gx.cfg \
		instset-heads-sex.cfg instset-heads.cfg instset-smt.cfg \
		instset-transsmt.cfg

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -name "CMakeLists.txt" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|-O[0-9]|| ; \
		 s| pthread| -pthread|'
	@${REINPLACE_CMD} -e '/long long int/s|std::abs|llabs|' \
		${WRKSRC}/avida-core/source/main/cPopulationInterface.cc
	@${REINPLACE_CMD} -e '/__PPC__/s|linux|${OPSYS}|' \
		${WRKSRC}/libs/tcmalloc-1.4/src/atomicops.h

pre-build:
.for exec in ${BIN_FILES}
	@(cd ${WRKSRC} && ${ECHO_CMD} \
		'cd ${PREFIX}/lib/${PORTNAME} && ./${exec} $$@' > ${exec}.sh)
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
.for exec in ${BIN_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${exec}.sh \
		${STAGEDIR}${PREFIX}/bin/${exec}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/${exec} \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
.endfor
	${INSTALL_DATA} \
		${WRKSRC}/avida-core/support/config/*.cfg \
		${WRKSRC}/avida-core/support/config/*.org \
			${STAGEDIR}${PREFIX}/lib/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/avida-core/documentation && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
