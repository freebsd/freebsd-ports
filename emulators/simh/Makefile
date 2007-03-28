# New ports collection makefile for:    sim
# Date created:         7 November 1997
# Whom:			jraynard
#
# $FreeBSD$
#

PORTNAME=	simh
PORTVERSION=	3.7
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
DISTNAME=	${PORTNAME}v37-0

MAINTAINER=	trasz@pin.if.uz.zgora.pl
COMMENT=	Emulates classic DEC, HP, GRI, IBM, Altair, SDS, Honeywell, and others

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qoa
USE_GMAKE=	yes
RESTRICTED=	Non-commercial use only
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

OPTIONS=	NETWORK	"Enable Sim_Ether module (and ports libpcap)"	on

BIN_FILES=	altair    h316   ibm1130 nova  pdp15 pdp9 vax780 \
		altairz80 hp2100 id16    pdp1  pdp4  s3          \
		i1401  id32    pdp10 pdp7  sds         \
		gri       i1620  lgp     pdp11 pdp8  vax

PORTDOCS=	0readme_37.txt 0readme_ethernet.txt

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
