# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phoronix-test-suite
PORTVERSION=	5.4.1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.phoronix-test-suite.com/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Phoronix Benchmarking Suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	fpdf>0:${PORTSDIR}/print/fpdf

USE_PHP=	ctype curl dom filter gd hash json openssl pcntl posix session \
	sockets sqlite3 zip zlib
USE_PHP_BUILD=	yes
WANT_PHP_CLI=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/phoronix-test-suite

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	BASH_COMPLETIONS X11 DOCS
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=	yes

BASH_COMPLETIONS_DESC=	Install bash completions
BASH_COMPLETIONS_CONFIGURE_ON=	WITH_BASH_COMPLETIONS=yes
X11_DESC=		Install X11 icons and mimetypes
X11_USES=	desktop-file-utils shared-mime-info
X11_CONFIGURE_OFF=	WITHOUT_X11=yes

post-patch:
	@${SED} -i '' -e "s|/usr/local|${LOCALBASE}|g" \
		${WRKSRC}/phoronix-test-suite \
		${WRKSRC}/pts-core/commands/ob_test_profile_analyze.php \
		${WRKSRC}/pts-core/external-test-dependencies/scripts/install-dragonfly-packages.sh \
		${WRKSRC}/pts-core/external-test-dependencies/xml/dragonfly-packages.xml \
		${WRKSRC}/pts-core/external-test-dependencies/xml/freebsd-packages.xml \
		${WRKSRC}/pts-core/objects/bilde_renderer/bilde_renderer.php \
		${WRKSRC}/pts-core/objects/client/pts_client.php
	@${SED} -i '' -e "s|/usr/share/fonts|${LOCALBASE}/lib/X11/fonts| ; \
		s|/usr/X11/lib|${LOCALBASE}/lib|" \
		${WRKSRC}/pts-core/objects/bilde_renderer/bilde_renderer.php
	@${SED} -i '' -e "/fpdf.php/s|/usr/share/php|${PREFIX}/share|" \
		${WRKSRC}/pts-core/pts-core.php \
		${WRKSRC}/pts-core/commands/dump_documentation.php \
		${WRKSRC}/pts-core/commands/result_file_to_pdf.php

do-install:
	(cd ${WRKSRC} && ${CONFIGURE_ARGS} DESTDIR="${STAGEDIR}" ./install-sh ${PREFIX})

.include <bsd.port.mk>
