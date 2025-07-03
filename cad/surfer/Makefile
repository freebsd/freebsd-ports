PORTNAME=	surfer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	cad

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	Extensible and snappy waveform viewer
WWW=		https://surfer-project.org

LICENSE=	EUPL12
LICENSE_FILE=	${WRKSRC}/LICENSE-EUPL-1.2.txt

USES=		cargo ssl

USE_GITLAB=	yes
GL_ACCOUNT=	surfer-project

# For vendored crates (git submodules)
USE_GITHUB=	nodefault		# Cannot use yes because USE_GITLAB=yes above
GL_TUPLE=	TheZoq2:fzcmd:1ae2b2c2e50ce7b99809dc7e2dd64749a51fd4f2:fzcmd
GH_TUPLE=	jkarns275:f128:e60de395f0d6454c1dc546b87f06a6358425b6b6:f128 \
		ics-jku:instruction-decoder:8894eaaf012df38a290f57c8867660eb65c114c3:instdec

PLIST_FILES=	bin/surfer

# Move vendored crates (git submodules) to the correct location
post-extract:
	${RM} -r ${WRKSRC}/fzcmd
	${MV} ${WRKSRC_fzcmd} ${WRKSRC}/fzcmd
	${RM} -r ${WRKSRC}/f128
	${MV} ${WRKSRC_f128} ${WRKSRC}/f128
	${RM} -r ${WRKSRC}/instruction-decoder
	${MV} ${WRKSRC_instdec} ${WRKSRC}/instruction-decoder

do-install:
# workaround for error: found a virtual manifest at `xx` instead of a package manifest
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/release/surfer \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
