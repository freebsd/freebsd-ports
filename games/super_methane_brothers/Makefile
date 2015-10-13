# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	super_methane_brothers
PORTVERSION=	1.5.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/methane/Methane%20Stable/Methane%20V${PORTVERSION}
DISTNAME=	methane-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of the Amiga platform game of the same name

LICENSE=	GPLv2

LIB_DEPENDS=	libclan23Core.so:${PORTSDIR}/devel/clanlib

USES=		execinfo gmake pkgconfig tar:tgz
USE_GCC=	yes
MAKE_ENV=	METHANE_FLAGS="${CPPFLAGS}" METHANE_LIBS="${LIBS}"
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lexecinfo

DATADIR=	${PREFIX}/share/methane

PORTDOCS=	*
PORTDATA=	*
PLIST_FILES=	bin/methane

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|-2.2|-2.3|g ; \
		 s|FLAGS =|FLAGS +=| ; \
		 s|LIBS =|LIBS +=| ; \
		 s|g++|$${CXX}| ; \
		 s|gcc|$${CXX}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/methane ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/resources && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKDIR}/${DISTNAME}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
