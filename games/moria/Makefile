# New ports collection makefile for:	moria
# Date created:		6 August 2003
# Whom:			glewis@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	moria
PORTVERSION=	5.5.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.funet.fi/pub/unix/games/moria/source/ \
		ftp://ftp.greyhelm.com/pub/Games/Moria/source/
DISTNAME=	um${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	A dungeon exploration game


MAN6=		moria.6
WRKSRC=		${WRKDIR}/umoria
ALL_TARGET=	moria
MAKE_ENV+=	DOCSDIR="${DOCSDIR}" MKDIR="${MKDIR}" CHOWN="${CHOWN}" \
	CHGRP="${CHGRP}" CHMOD="${CHMOD}" TOUCH="${TOUCH}"

do-configure:
	for i in ${WRKSRC}/source/config.h ${WRKSRC}/unix/Makefile; do \
		${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" $$i; \
	done
	cd ${WRKSRC} && ${LN} -sf source/* unix/* .

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	for i in ${MAN6}; do \
		${INSTALL_MAN} ${WRKSRC}/doc/$$i ${PREFIX}/man/man6; \
	done
.endif
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install
.endif

.include <bsd.port.mk>
