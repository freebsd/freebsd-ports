# New ports collection makefile for:	lbreakout2
# Date created:		12 June 2002
# Whom:			verm@drunkmonk.net
#
# $FreeBSD$
#

PORTNAME=	lbreakout2
DISTVERSION=	2.6beta
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lgames

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	The polished successor to LBreakout

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_SDL=	mixer net sdl
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-sdl-net \
		--localstatedir=/var/games
CONFIGURE_TARGET=

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's|== "-D|= "-D|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|client docs|client|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|: install-data-local|:|g' ${WRKSRC}/client/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/client/empty.hscr ${DATADIR}
	@${CHOWN} root:games ${PREFIX}/bin/lbreakout2
	@${CHMOD} g+s ${PREFIX}/bin/lbreakout2
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.jpg ${DOCSDIR}
.endif
	@${SETENV} "PKG_PREFIX=${PREFIX}" \
		${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
