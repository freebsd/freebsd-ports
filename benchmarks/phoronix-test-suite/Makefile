# New ports collection makefile for:	phoronix
# Date created:				Jul 1, 2009
# Whom:					Kris Moore <kmoore@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phoronix-test-suite
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.phoronix-test-suite.com/releases/ \
		http://www.phoronix.com/downloads/phoronix-test-suite/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Phoronix Benchmarking Suite

OPTIONS=	X11	"Enable support for php-gtk2 GUI"  on

USE_PHP=	yes
USE_PHP_BUILD=	yes
WANT_PHP_CLI=	yes
USE_GZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/phoronix-test-suite
MAN1=		phoronix-test-suite.1

DOCFILES1=	CHANGE-LOG COPYING AUTHORS
DOCFILES2=	includes/pts-documentation.png includes/pts-documentation.css \
		tips_and_tricks.html specifications_xml_test.html specifications_xml_suite.html \
		specifications_xml_download.html sensor_monitoring.html pts_options.html \
		install.html index.html default_files.html writing_your_first_test.html \
		credits.html writing_your_first_module.html

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/php_gtk2.so:${PORTSDIR}/x11-toolkits/php-gtk2
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/share/man/man1|/man/man1|g" ${WRKSRC}/install-sh
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" \
				${WRKSRC}/phoronix-test-suite \
				${WRKSRC}/pts/test-resources/yafray/install.sh \
				${WRKSRC}/pts/test-resources/etqw/install.sh \
				${WRKSRC}/pts/test-resources/mafft/install.sh \
				${WRKSRC}/pts/distro-xml/freebsd-packages.xml \
				${WRKSRC}/pts-core/library/pts-functions_shell.php

do-install:
	cd ${WRKSRC} && ./install-sh ${LOCALBASE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/includes
.for FILE in ${DOCFILES1}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
.endfor
.for FILE in ${DOCFILES2}
	@${INSTALL_DATA} ${WRKSRC}/documentation/${FILE} ${DOCSDIR}/${FILE}
.endfor
	@${ECHO_MSG} "===> Docs installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
