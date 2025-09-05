PORTNAME=	prestashop
PORTVERSION=	8.2.3
CATEGORIES=	finance www
MASTER_SITES=	https://github.com/PrestaShop/PrestaShop/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open-Source e-Commerce Software for Web 2.0
WWW=		https://www.prestashop.com/

USES=		cpe php shebangfix zip:infozip
NO_BUILD=	yes
PRESTADIR=	www/${PORTNAME}
PLIST=		${WRKDIR}/plist
USE_PHP=	ctype curl dom fileinfo filter gd intl \
		mbstring mcrypt mysqli \
		pdo_mysql posix session simplexml \
		soap tokenizer zip

WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message

post-extract:
	@(cd ${WRKDIR} && ${UNZIP_CMD} -d prestashop ${WRKDIR}/prestashop.zip)
	${REINPLACE_CMD} -e 's#@prefix@#${PREFIX}#g' \
		${WRKSRC}/vendor/pear/archive_tar/scripts/phptar.in

pre-install:
	@${ECHO_CMD} -e '@owner ${WWWOWN}\n@group ${WWWGRP}' > ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${PRESTADIR}?g" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${PRESTADIR}?g" >> ${PLIST}
	@${ECHO_CMD} -e '@owner root\n@group wheel' >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
