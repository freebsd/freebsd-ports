# New ports collection makefile for:	marbles
# Date created:		12 June 2002
# Whom:			verm@drunkmonk.net
#
# $FreeBSD$
#

PORTNAME=	marbles
PORTVERSION=	1.0.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lgames
DISTNAME=	lmarbles-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A challenging puzzle game similar to Atomix

USE_SDL=	sdl mixer
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games
USE_REINPLACE=	yes

MAN6=		lmarbles.6

post-patch:
	@${REINPLACE_CMD} -e 's/SDL\///' ${WRKSRC}/src/*.[ch]

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/empty.prfs ${PREFIX}/share/lmarbles
	@${CHOWN} root:games ${PREFIX}/bin/lmarbles
	@${CHMOD} g+s ${PREFIX}/bin/lmarbles
	@${SETENV} "PKG_PREFIX=${PREFIX}" \
		${SH} pkg-install ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/lmarbles
	${INSTALL_DATA} ${WRKSRC}/src/manual/* ${PREFIX}/share/doc/lmarbles
.endif

.include <bsd.port.mk>
