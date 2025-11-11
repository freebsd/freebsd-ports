PORTNAME=	surfer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	1
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
GH_TUPLE=	jkarns275:f128:e60de395f0d6454c1dc546b87f06a6358425b6b6:f128 \
		ics-jku:instruction-decoder:7c5adb7621a6f277ee13ec1a4babe32ce56cc0c3:instdec

PLIST_FILES=	bin/surfer

# Move vendored crates (git submodules) to the correct location
post-extract:
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
