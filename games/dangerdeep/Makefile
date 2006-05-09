# New ports collection makefile for:	dangerdeep
# Date created:		2005-10-28
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	dangerdeep
PORTVERSION=	0.1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dangerdeep

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Open source World War II German submarine simulation

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	fftw3.3:${PORTSDIR}/math/fftw3 \
		execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_X_PREFIX=	yes
USE_GL=		yes
USE_SDL=	sdl mixer image net

MAKE_ENV=	CC="${CC}" CXX="${CXX}"
SCONS_ARGS=	installbindir=${PREFIX}/bin installdatadir=${DATADIR}

PLIST=		${WRKDIR}/pkg-plist
PLIST_FILES=	bin/dangerdeep bin/crosssection bin/damagemodel \
		bin/oceantest bin/portal bin/viewmodel
PLIST_DIRS=	%%DATADIR%%

MAN6=		dangerdeep.6
PORTDOCS=	CREDITS README

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not build on FreeBSD 4.x
.endif

.if defined(PACKAGE_BUILDING)
SCONS_ARGS+=	usex86sse=-1	# disable MMX/SSE on the build cluster
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/games/dangerdeep|${DATADIR}|; \
		s|Linux|"Danger from the Deep"|' ${WRKSRC}/doc/man/dangerdeep.6

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} scons ${SCONS_ARGS}

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC}/data && \
	${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}

do-install:
	@cd ${WRKSRC}/build/freebsd && \
		${INSTALL_PROGRAM} dangerdeep crosssection damagemodel oceantest \
			portal viewmodel ${PREFIX}/bin

	cd ${WRKSRC}/data && \
	${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

	${INSTALL_MAN} ${WRKSRC}/doc/man/dangerdeep.6 ${PREFIX}/man/man6

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
