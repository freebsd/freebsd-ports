# New ports collection makefile for:    sim
# Date created:         7 November 1997
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	sim
PORTVERSION=	3.2.0
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
DISTNAME=	${PORTNAME}hv32-0

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	PDP-8, PDP-11, PDP-1, other 18b PDP, Nova, and IBM 1401 simulators

USE_ZIP=	yes
USE_GMAKE=	yes
RESTRICTED=	"Non-commercial use only"
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

SHELL=${SH}

BIN_FILES=	pdp1 pdp4 pdp7 pdp8 pdp9 \
		pdp15 pdp11 pdp10 vax nova \
		eclipse h316 hp2100 i1401 \
		i1620 s3 altair altairz80 \
		gri ibm1130 id16 id32 sds lgp

PORTDOCS=	0readme_32.txt simh_doc.txt simh_swre.txt \
		0readme_ethernet.txt simh_faq.txt

PLIST_FILES=	${BIN_FILES:S/^/bin\//g} share/sim/ka655.bin share/sim/ka655x.bin
PLIST_DIRS=	share/sim

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
	${INSTALL_DATA} ${WRKDIR}/VAX/ka655*.bin ${PREFIX}/share/sim

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for i in ${PORTDOCS}; do\
		${INSTALL_DATA} ${WRKDIR}/$$i ${DOCSDIR}; \
	done
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
