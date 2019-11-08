# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	prestashop
PORTVERSION=	1.7.6.1
PORTREVISION=	1
CATEGORIES=	finance www
MASTER_SITES=	http://www.prestashop.com/download/old/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open-Source e-Commerce Software for Web 2.0

USES=		cpe php shebangfix zip:infozip
NO_BUILD=	yes
PRESTADIR=	www/${PORTNAME}
PLIST=		${WRKDIR}/plist
USE_PHP=	ctype curl dom filter gd hash intl json mcrypt \
		mysqli pdo_mysql posix session simplexml soap
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message

SHEBANG_FILES=	vendor/swiftmailer/swiftmailer/lib/swiftmailer_generate_mimes_config.php \
		vendor/doctrine/orm/docs/bin/generate-docs.sh \
		vendor/doctrine/orm/docs/bin/install-dependencies.sh \
		vendor/symfony/symfony/src/Symfony/Component/Intl/Tests/Data/Bundle/Reader/Fixtures/build.sh \
		vendor/tecnickcom/tcpdf/tools/tcpdf_addfont.php

post-extract:
	@(cd ${WRKDIR} && ${UNZIP_CMD} -d prestashop ${WRKDIR}/prestashop.zip)
	${REINPLACE_CMD} -e 's#@prefix@#${PREFIX}#g' \
		${WRKSRC}/vendor/pear/archive_tar/scripts/phptar.in
	${RM} ${WRKSRC}/vendor/pear/archive_tar/scripts/*.bak

pre-install:
	@${ECHO_CMD} -e '@owner ${WWWOWN}\n@group ${WWWGRP}' > ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${PRESTADIR}?g" >> ${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dir ${PRESTADIR}?g" >> ${PLIST}
	@${ECHO_CMD} -e '@owner root\n@group wheel' >> ${PLIST}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
