# New ports collection makefile for:    sim
# Date created:         7 November 1997
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	sim
PORTVERSION=	2.10.1
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=jedgar
DISTNAME=	${PORTNAME}hv210-1

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	PDP-8, PDP-11, PDP-1, other 18b PDP, Nova, and IBM 1401 simulators

USE_ZIP=	yes
USE_GMAKE=	yes
RESTRICTED=	"Non-commercial use only"
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

SHELL=${SH}

BIN_FILES=	altair h316 ibm1130 pdp11 pdp8 \
		altairz80 hp2100 nova pdp15 pdp9 \
		eclipse i1401 pdp1 pdp4 s3 \
		gri i1620 pdp10 pdp7 vax \

pre-patch:
	@${MKDIR} ${WRKSRC}/BIN
	@for i in ${WRKSRC}/makefile `${FIND} ${WRKSRC} -name "*.[hc]"`; do \
		${CAT} $$i | ${TR} -d '\r' > $$i.new; \
		${MV} $$i.new $$i; \
	done

do-install:
.for file in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKDIR}/BIN/${file} ${PREFIX}/bin
.endfor

	@${MKDIR} ${PREFIX}/share/sim
	${INSTALL_DATA} ${WRKDIR}/VAX/ka655.bin ${PREFIX}/share/sim

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/sim
	@for i in 0readme_210.txt 0readme_ethernet.txt \
			simh_doc.txt simh_swre.txt; do \
	${INSTALL_DATA} ${WRKDIR}/$$i ${PREFIX}/share/doc/sim; \
	done
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
