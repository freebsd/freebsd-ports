# New ports collection makefile for:    sim
# Date created:         7 November 1997
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	sim
PORTVERSION=	2.9
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=jedgar
DISTNAME=	${PORTNAME}hv29

MAINTAINER=	jedgar@FreeBSD.org

USE_ZIP=	yes
RESTRICTED=	"Non-commercial use only"
MAKEFILE=	${FILESDIR}/Makefile
NO_WRKSUBDIR=	yes

SHELL=${SH}

post-configure:
	@${MKDIR} ${WRKSRC}/BIN
	@for i in `find . -name "*.[hc]"`; \
	do \
		${PERL} -pi -e 's@\r@@g' $$i ;\
	done

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/BIN/nova ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/BIN/pdp1 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/BIN/pdp4 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/BIN/pdp7 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/BIN/pdp8 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/BIN/pdp9 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/BIN/pdp11 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/BIN/pdp15 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/sim && ${INSTALL_DATA} ${WRKDIR}/simh_doc.txt \
		${PREFIX}/share/doc/sim
.endif

.include <bsd.port.mk>
