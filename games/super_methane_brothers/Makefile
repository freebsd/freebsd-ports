# New ports collection makefile for:	Super Methane Brothers
# Date created:			22 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	super_methane_brothers
PORTVERSION=	1.4.7
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	methane
DISTNAME=	methane-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A port of the Amiga platform game of the same name

LIB_DEPENDS=	clanCore-0.7:${PORTSDIR}/devel/clanlib-devel \
		mikmod:${PORTSDIR}/audio/libmikmod

BUILD_WRKSRC=	${WRKSRC}/source/linux
MAKEFILE=	makefile

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not compile on FreeBSD 4.X
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|g++|${CXX}|; s|gcc|${CXX}|; \
		 s|\(clanCore-0.7\)|\1 clanSignals-0.7|; \
		 s|^\(METHANE_FLAGS =\)|\1 -I${X11BASE}/include|; \
		 s|^\(METHANE_LIBS =\)|\1 -L${X11BASE}/lib|' \
		${BUILD_WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/methane ${PREFIX}/bin
	${CHGRP} games ${PREFIX}/bin/methane
	${CHMOD} g+s ${PREFIX}/bin/methane
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/authors \
		${WRKSRC}/history \
		${WRKSRC}/readme \
		${WRKSRC}/todo \
		${DOCSDIR}
	${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs/*.gif ${WRKSRC}/docs/*.html \
		${DOCSDIR}/html
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
