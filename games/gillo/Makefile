# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	gillo
DISTVERSION=	1.0beta1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.0beta1
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Players are cars throwing a magnetic fuzzy ball into a goal

LICENSE=	GPLv2

BUILD_DEPENDS=	${JAM}:${PORTSDIR}/devel/jam \
		${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode \
		${LOCALBASE}/lib/libplibsg.a:${PORTSDIR}/x11-toolkits/plib

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		tar:bzip2
USE_GL=		glu
USE_SDL=	yes

JAM?=		${LOCALBASE}/bin/jam

post-patch:
	@${REINPLACE_CMD} '/^LINKLIBS on gillo3/s|;$$|-L${LOCALBASE}/lib -lm ;|' \
		${WRKSRC}/src/Jamfile

do-build:
	cd ${WRKSRC} && ${SETENV} C++="${CXX}" C++FLAGS="${CXXFLAGS}" \
		CCFLAGS="${CFLAGS} -DDATADIR=\\\"${PREFIX}/share\\\"" \
		HDRS="${LOCALBASE}/include" \
		LINK="${CXX}" LINKFLAGS="${LDFLAGS}" \
		${JAM} -dx -sPREFIX=${PREFIX}

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} gillo3 ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/data && ${INSTALL_DATA} *.* ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
