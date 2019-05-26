# $FreeBSD$

PORTNAME=	goesimage
DISTVERSION=	0.1.1
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wallpapers from NOAA Geostationary Operational Environment Satellite

RUN_DEPENDS=	bash:shells/bash \
		curl:ftp/curl \
		feh:graphics/feh \
		convert:graphics/ImageMagick6

USES=		shebangfix
SHEBANG_FILES=	goesimage
USE_GITHUB=	yes
GH_ACCOUNT=	pigmonkey

NO_BUILD=	yes
NO_ARCH=	yes

SUB_LIST=	PORTNAME=${PORTNAME}
SUB_FILES=	crontab

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/crontab ${STAGEDIR}${DATADIR}
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "crontab -l | ${GREP} -v '${PREFIX}/libexec/${PORTNAME}' | (cat ; cat ${DATADIR}/crontab) | crontab -;"; \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-enable
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "crontab -l | ${GREP} -v '${PREFIX}/libexec/${PORTNAME}' | crontab -"; \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-disable
	@cd ${STAGEDIR}${PREFIX}/bin && ${CHMOD} +x ${PORTNAME}-enable ${PORTNAME}-disable

.include <bsd.port.mk>
