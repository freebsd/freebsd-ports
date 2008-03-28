# New ports collection makefile for:	primateplunge
# Date created:		2006-02-01
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	primateplunge
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.aelius.com/primateplunge/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Primate Plunge is an arcade game

RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
PRIMATEDIR=	sounds graphics

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/src/primateplunge ${PREFIX}/bin/primateplunge
	@cd ${WRKSRC} && \
		${FIND}	${PRIMATEDIR} -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} -E ${PRIMATEDIR} -type f -iregex ".*\.(bmp|wav|mid)" -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/AUTHORS ${WRKSRC}/TIPS ${DOCSDIR}
.endif

.include <bsd.port.mk>
