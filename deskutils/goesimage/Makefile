# $FreeBSD$

PORTNAME=	goesimage
DISTVERSION=	0.1.1-1
DISTVERSIONSUFFIX=	-g0021b16
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wallpapers from NOAA Geostationary Operational Environment Satellite

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	bash:shells/bash \
		convert:graphics/ImageMagick6 \
		curl:ftp/curl \
		feh:graphics/feh

USES=		shebangfix
SHEBANG_FILES=	goesimage
USE_GITHUB=	yes
GH_ACCOUNT=	pigmonkey

NO_BUILD=	yes
NO_ARCH=	yes

SUB_LIST=	PORTNAME=${PORTNAME} RUN_ARGS="${RUN_ARGS}"
SUB_FILES=	crontab

RUN_ARGS=	-w -e

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/crontab ${STAGEDIR}${DATADIR}
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "crontab -l | ${GREP} -v '${PREFIX}/libexec/${PORTNAME}' | (cat ; cat ${DATADIR}/crontab) | crontab -"; \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-enable
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "crontab -l | ${GREP} -v '${PREFIX}/libexec/${PORTNAME}' | crontab -"; \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-disable
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "${PREFIX}/libexec/${PORTNAME} ${RUN_ARGS}"; \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-run-now
	@cd ${STAGEDIR}${PREFIX}/bin && ${CHMOD} +x ${PORTNAME}-enable ${PORTNAME}-disable ${PORTNAME}-run-now

.include <bsd.port.mk>
