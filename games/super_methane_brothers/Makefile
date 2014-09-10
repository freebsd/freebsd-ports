# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	super_methane_brothers
PORTVERSION=	1.5.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/methane/Methane%20Stable/Methane%20V${PORTVERSION}
DISTNAME=	methane-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of the Amiga platform game of the same name

LICENSE=	GPLv2

LIB_DEPENDS=	libclan23Core.so:${PORTSDIR}/devel/clanlib \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo

USES=		gmake pkgconfig tar:tgz
USE_GCC=	yes
USE_GL=		glu
MAKE_ENV=	METHANE_FLAGS="${CPPFLAGS}" METHANE_LIBS="${LIBS}"
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lexecinfo

PORTDOCS=	*
PLIST_FILES=	bin/methane

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|-2.2|-2.3|g ; \
		 s|FLAGS =|FLAGS +=| ; \
		 s|LIBS =|LIBS +=| ; \
		 s|g++|$${CXX}| ; \
		 s|gcc|$${CXX}|' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKDIR}/${DISTNAME} && ${INSTALL_PROGRAM} methane ${STAGEDIR}${PREFIX}/bin)
	${CHGRP} games ${STAGEDIR}${PREFIX}/bin/methane
	${CHMOD} g+s ${STAGEDIR}${PREFIX}/bin/methane
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKDIR}/${DISTNAME}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
