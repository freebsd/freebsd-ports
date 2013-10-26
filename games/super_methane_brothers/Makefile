# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	super_methane_brothers
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/methane/Methane%20Stable/Methane%20V${PORTVERSION}
DISTNAME=	methane-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	Port of the Amiga platform game of the same name

LICENSE=	GPLv2

LIB_DEPENDS=	clan23Core:${PORTSDIR}/devel/clanlib \
		execinfo:${PORTSDIR}/devel/libexecinfo

USES=		gmake pkgconfig
USE_GCC=	yes
USE_GL=		glu
MAKE_ENV=	METHANE_FLAGS="${CPPFLAGS}" METHANE_LIBS="${LDFLAGS}"
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo

PORTDOCS=	*
PLIST_FILES=	bin/methane

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|-2.2|-2.3|g ; \
		 s|FLAGS =|FLAGS +=| ; \
		 s|LIBS =|LIBS +=| ; \
		 s|g++|$${CXX}| ; \
		 s|gcc|$${CXX}|' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKDIR}/${DISTNAME} && ${INSTALL_PROGRAM} methane ${PREFIX}/bin)
	${CHGRP} games ${PREFIX}/bin/methane
	${CHMOD} g+s ${PREFIX}/bin/methane
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKDIR}/${DISTNAME}/docs && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
