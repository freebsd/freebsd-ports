# New ports collection makefile for:	marbles
# Date created:		12 June 2002
# Whom:			verm@drunkmonk.net
#
# $FreeBSD$
#

PORTNAME=	marbles
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lgames

MAINTAINER=	verm@drunkmonk.net
COMMENT=	A challenging puzzle game similar to Atomix

USE_SDL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-profile-path=/var/games
USE_REINPLACE=	yes

MAN6=	marbles.6

post-patch:
	@${REINPLACE_CMD} -e 's/SDL\///' ${WRKSRC}/src/*.[ch]
	@${REINPLACE_CMD} -e 's/^#include "sys\/timeb.h"//' \
		${WRKSRC}/src/timer.c
	@${REINPLACE_CMD} -e 's/games\/marbles/marbles/g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/if .*marbles.prfs/if false/' \
		${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/empty.prfs ${DATADIR}
	@${CHOWN} root:games ${PREFIX}/bin/marbles
	@${CHMOD} g+s ${PREFIX}/bin/marbles
	@${SETENV} "PKG_PREFIX=${PREFIX}" \
		${SH} pkg-install ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/manual/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
