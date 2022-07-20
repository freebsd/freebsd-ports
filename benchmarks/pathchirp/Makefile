PORTNAME=	pathchirp
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.spin.rice.edu/Software/pathChirp/

MAINTAINER=	dikshie@lapi.itb.ac.id
COMMENT=	Measurement tool for available bandwidth estimation

LICENSE=		RICE MARYLAND
LICENSE_COMB=		multi
LICENSE_NAME_RICE=	Rice University License
LICENSE_FILE_RICE=	${PATCHDIR}/LICENSE-RICE
LICENSE_PERMS_RICE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_NAME_MARYLAND=	University of Maryland License
LICENSE_FILE_MARYLAND=	${PATCHDIR}/LICENSE-MARYLAND
LICENSE_PERMS_MARYLAND=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
USES=		gmake
USE_CSTD=	gnu89
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/pathchirp_rcv bin/pathchirp_snd bin/pathchirp_run
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS.*O4/d' ${WRKSRC}/configure

do-install:
.for f in rcv snd run
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/${ARCH}/${PORTNAME}_${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
