# New ports collection makefile for:    sim
# Date created:         7 November 1997
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	sim
PORTVERSION=	2.9.11
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=jedgar
DISTNAME=	${PORTNAME}hv29-11

MAINTAINER=	jedgar@FreeBSD.org

USE_ZIP=	yes
RESTRICTED=	"Non-commercial use only"
MAKEFILE=	${FILESDIR}/Makefile
NO_WRKSUBDIR=	yes

SHELL=${SH}

BIN_FILES=	altair eclipse h316 nova pdp1 pdp10 pdp11 pdp15 pdp4 pdp7 pdp8 \
		pdp9 s3

pre-patch:
	@${MKDIR} ${WRKSRC}/BIN
	@for i in `find ${WRKSRC} -name "*.[hc]"`; do \
		cat $$i | ${TR} -d '\r' > $$i.new; \
		mv $$i.new $$i; \
	done

do-install:
.for file in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKDIR}/BIN/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/sim
	@${INSTALL_DATA} ${WRKDIR}/simh_doc.txt ${PREFIX}/share/doc/sim
.endif

.include <bsd.port.mk>
