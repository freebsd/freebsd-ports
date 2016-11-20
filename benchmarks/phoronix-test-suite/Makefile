# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phoronix-test-suite
PORTVERSION=	6.6.1
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.phoronix-test-suite.com/releases/

MAINTAINER=	luca.pizzamiglio@gmail.com
COMMENT=	Phoronix Benchmarking Suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		php:cli,build
USE_GCC=	any
USE_PHP=	ctype curl dom filter gd hash json openssl pcntl posix session \
	simplexml sockets sqlite3 zip zlib
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/phoronix-test-suite

RUN_DEPENDS+=	fpdf>0:print/fpdf
RUN_DEPENDS+=	cmake:devel/cmake

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
		${WRKSRC}/pts-core/pts-core.php \
		${WRKSRC}/pts-core/objects/pts_svg_dom_gd.php \
		${WRKSRC}/pts-core/objects/phodevi/components/phodevi_system.php \
		${WRKSRC}/pts-core/objects/client/pts_external_dependencies.php \
		${WRKSRC}/pts-core/objects/client/pts_client.php \
		${WRKSRC}/pts-core/external-test-dependencies/scripts/install-dragonfly-packages.sh \
		${WRKSRC}/pts-core/external-test-dependencies/xml/freebsd-packages.xml
	@${SED} -i '' -e "s|/usr/share/fonts|${LOCALBASE}/share/fonts| ; \
		s|/usr/X11/lib|${LOCALBASE}/lib|" \
		${WRKSRC}/pts-core/objects/pts_svg_dom_gd.php
	@${SED} -i '' -e "/fpdf.php/s|/usr/share/php|${PREFIX}/share|" \
		${WRKSRC}/pts-core/objects/pts_pdf_template.php
		#${WRKSRC}/pts-core/pts-core.php \
		#${WRKSRC}/pts-core/commands/dump_documentation.php \
		#${WRKSRC}/pts-core/commands/result_file_to_pdf.php

do-install:
	(cd ${WRKSRC} && ${CONFIGURE_ARGS} DESTDIR="${STAGEDIR}" ./install-sh ${PREFIX})

.include <bsd.port.mk>
