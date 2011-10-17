# New ports collection makefile for:	dangerdeep
# Date created:		2005-10-28
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	dangerdeep
PORTVERSION=	0.3.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/danger_from_the_deep-src/${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Open source World War II German submarine simulation

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		execinfo.1:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/maps/default.xml:${PORTSDIR}/games/dangerdeep-data

USE_GL=		yes
USE_SDL=	sdl mixer image net

SCONS_ARGS=	installbindir=${PREFIX}/bin installdatadir=${DATADIR}

PLIST_FILES=	bin/dangerdeep bin/crosssection bin/damagemodel \
		bin/oceantest bin/portal bin/viewmodel
PLIST_DIRS=	%%DATADIR%%

MAN6=		dangerdeep.6
PORTDOCS=	CREDITS README

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING)
SCONS_ARGS+=	usex86sse=-1	# disable MMX/SSE on the build cluster
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/games/dangerdeep|${DATADIR}|; \
		s|Linux|"Danger from the Deep"|' ${WRKSRC}/doc/man/dangerdeep.6
	@${REINPLACE_CMD} -e 's|/usr/X11BASE|${LOCALBASE}|g' \
	    ${WRKSRC}/SConstruct

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} scons ${SCONS_ARGS}

do-install:
	@cd ${WRKSRC}/build/freebsd && \
		${INSTALL_PROGRAM} dangerdeep crosssection damagemodel oceantest \
			portal viewmodel ${PREFIX}/bin

	${INSTALL_MAN} ${WRKSRC}/doc/man/dangerdeep.6 ${PREFIX}/man/man6

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
