# New ports collection makefile for:    sim
# Date created:         7 November 1997
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	simh
PORTVERSION=	3.8.0
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
DISTNAME=	${PORTNAME}v38-0

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Emulates classic DEC, HP, GRI, IBM, Altair, SDS, Honeywell, and others

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qoa
USE_GMAKE=	yes
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

OPTIONS=	NETWORK	"Enable Sim_Ether module (and ports libpcap)"	on

BIN_FILES=	altair altairz80 gri h316 hp2100 i1401 i1620 i7094 ibm1130 \
		id16 id32 lgp nova pdp1 pdp10 pdp11 pdp15 pdp4 pdp7 pdp8 pdp9 \
		s3 sds vax vax780 

PORTDOCS=	0readme_38.txt 0readme_ethernet.txt

PLIST_FILES=	${BIN_FILES:S/^/bin\//g} %%DATADIR%%/ka655x.bin bin/simh-eclipse
PLIST_DIRS=	%%DATADIR%%

SUB_FILES+=	pkg-message

.include <bsd.port.pre.mk>

# XXX How do we know that libpcap.a is really the correct >0.9.x version?!
.if defined (WITH_NETWORK)
RUN_DEPENDS=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
BUILD_DEPENDS=	${RUN_DEPENDS}
MAKE_ENV=	USE_NETWORK=1
.endif

pre-patch:
	@${MKDIR} ${WRKSRC}/BIN

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/VAX/vax_sysdev.c

do-install:
.for file in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKDIR}/BIN/${file} ${PREFIX}/bin
.endfor
# eclipse conflicts with java/eclipse, install it as simh-eclipse
	${INSTALL_PROGRAM} ${WRKDIR}/BIN/eclipse ${PREFIX}/bin/simh-eclipse

	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/VAX/ka655x.bin ${DATADIR}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for i in ${PORTDOCS}; do\
		${INSTALL_DATA} ${WRKDIR}/$$i ${DOCSDIR}; \
	done
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
