# New ports collection makefile for:    sim
# Date created:         7 November 1997
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	sim
PORTVERSION=	3.5.2
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
DISTNAME=	${PORTNAME}hv35-2

MAINTAINER=	mmendez@energyhq.be
COMMENT=	Emulates classic DEC, HP, GRI, IBM, Altair, SDS, Honeywell, and others

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qoa
USE_GMAKE=	yes
RESTRICTED=	Non-commercial use only
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

SHELL=${SH}

OPTIONS=	NETWORK	"Enable Sim_Ether module (and ports libpcap)"	on

BIN_FILES=	altair    h316   ibm1130 nova  pdp15 pdp9 vax780 \
		altairz80 hp2100 id16    pdp1  pdp4  s3          \
		eclipse   i1401  id32    pdp10 pdp7  sds         \
		gri       i1620  lgp     pdp11 pdp8  vax

PORTDOCS=	0readme_35.txt simh_doc.txt simh_swre.txt \
		0readme_ethernet.txt simh_faq.txt

PLIST_FILES=	${BIN_FILES:S/^/bin\//g} %%DATADIR%%/ka655x.bin
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

# XXX How do we know that libpcap.a is really the correct >0.9.x version?!
.if defined (WITH_NETWORK)
RUN_DEPENDS=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
BUILD_DEPENDS=	${RUN_DEPENDS}
MAKE_ENV=	USE_NETWORK=1
.endif

pre-patch:
	@${MKDIR} ${WRKSRC}/BIN

do-install:
.for file in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKDIR}/BIN/${file} ${PREFIX}/bin
.endfor

	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/VAX/ka655x.bin ${DATADIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for i in ${PORTDOCS}; do\
		${INSTALL_DATA} ${WRKDIR}/$$i ${DOCSDIR}; \
	done
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.post.mk>
