# Ports collection makefile for:  klone
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Klone
PORTVERSION=	2.1.359
CATEGORIES=	lang
MASTER_SITES=	ftp://koala.inria.fr/pub/Klone/
DISTNAME=	Klone359

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/Klone

post-extract:
	@sed -e s#!!PREFIX!!#${PREFIX}# \
		${FILESDIR}/freebsd > ${WRKSRC}/Configs/freebsd

do-configure:
	@cp -f ${WRKSRC}/Configs/freebsd ${WRKSRC}/Config.freebsd
	@echo "freebsd" > ${WRKSRC}/.dir
	@rm -f makefile

do-install:
	${MKDIR} ${PREFIX}/lib/klone/scripts
	${INSTALL_PROGRAM} ${WRKSRC}/klone ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/kl/* ${PREFIX}/lib/klone
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/lib/klone/scripts
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/klone
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/klone
.endif

.include <bsd.port.mk>
