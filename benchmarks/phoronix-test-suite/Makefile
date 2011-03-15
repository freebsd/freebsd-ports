# New ports collection makefile for:	phoronix
# Date created:				Jul 1, 2009
# Whom:					Kris Moore <kmoore@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phoronix-test-suite
PORTVERSION=	3.0.1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.phoronix-test-suite.com/releases/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Phoronix Benchmarking Suite

OPTIONS=	BASH_COMPLETIONS "Install bash completions" off \
		X11 "Install X11 icons and mimetypes" on

USE_PHP=	zip json openssl gd zlib pcntl posix curl
USE_PHP_BUILD=	yes
WANT_PHP_CLI=	yes
USE_GZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/phoronix-test-suite
MAN1=		phoronix-test-suite.1

PORTDOCS=	*

DOCFILES1=	CHANGE-LOG COPYING AUTHORS

DOCFILES2=	phoronix-test-suite.pdf specifications_xml_test.html \
		specifications_xml_download.html writing_your_first_module.html \
		specifications_xml_suite.html writing_your_first_test.html

.include <bsd.port.options.mk>

.if !defined(WITHOUT_X11)
X11_DEPENDS=	${LOCALBASE}/bin/xdg-mime:${PORTSDIR}/devel/xdg-utils \
		${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		${LOCALBASE}/bin/update-mime-database:${PORTSDIR}/misc/shared-mime-info
BUILD_DEPENDS+=	${X11_DEPENDS}
RUN_DEPENDS+=	${X11_DEPENDS}
PLIST_SUB+=	X11=""
.else
INSTALL_OPTS=	WITHOUT_X11=yes
PLIST_SUB+=	X11="@comment "
.endif

.if defined(WITH_BASH_COMPLETIONS)
INSTALL_OPTS+=	WITH_BASH_COMPLETIONS=yes
PLIST_SUB+=	BASH_COMPLETIONS=""
.else
PLIST_SUB+=	BASH_COMPLETIONS="@comment "
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|/share/man/man1|/man/man1|g" ${WRKSRC}/install-sh
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" \
				${WRKSRC}/phoronix-test-suite \
				${WRKSRC}/pts-core/objects/bilde_renderer/bilde_renderer.php \
				${WRKSRC}/pts-core/objects/pts_client.php \
				${WRKSRC}/pts-core/external-test-dependencies/xml/freebsd-packages.xml

do-install:
	cd ${WRKSRC} && ${INSTALL_OPTS} ./install-sh ${PREFIX}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCFILES1}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
.endfor
.for FILE in ${DOCFILES2} 
	@${INSTALL_DATA} ${WRKSRC}/documentation/${FILE} ${DOCSDIR}/${FILE}
.endfor
.for DIR in html_sections includes 
	@${CP} -rf ${WRKSRC}/documentation/${DIR} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Docs installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
