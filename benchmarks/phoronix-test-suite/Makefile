# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phoronix-test-suite
PORTVERSION=	5.2.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.phoronix-test-suite.com/releases/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Phoronix Benchmarking Suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_PHP=	zip json openssl gd zlib pcntl posix curl ctype
USE_PHP_BUILD=	yes
WANT_PHP_CLI=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/phoronix-test-suite

PORTDOCS=	*
DOCFILES1=	CHANGE-LOG AUTHORS
DOCFILES2=	phoronix-test-suite.html

OPTIONS_DEFINE=	BASH_COMPLETIONS X11 DOCS
OPTIONS_DEFAULT=	X11

BASH_COMPLETIONS_DESC=	Install bash completions
X11_DESC=		Install X11 icons and mimetypes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USES+=		shared-mime-info
PLIST_SUB+=	X11=""
.else
INSTALL_OPTS=	WITHOUT_X11=yes
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MBASH_COMPLETIONS}
INSTALL_OPTS+=	WITH_BASH_COMPLETIONS=yes
PLIST_SUB+=	BASH_COMPLETIONS=""
.else
PLIST_SUB+=	BASH_COMPLETIONS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" \
				${WRKSRC}/phoronix-test-suite \
				${WRKSRC}/pts-core/objects/bilde_renderer/bilde_renderer.php \
				${WRKSRC}/pts-core/objects/client/pts_client.php \
				${WRKSRC}/pts-core/external-test-dependencies/xml/freebsd-packages.xml
	@${RM} ${WRKSRC}/phoronix-test-suite.bak \
		${WRKSRC}/pts-core/objects/bilde_renderer/bilde_renderer.php.bak \
		${WRKSRC}/pts-core/objects/client/pts_client.php.bak \
		${WRKSRC}/pts-core/external-test-dependencies/xml/freebsd-packages.xml.bak

do-install:
	cd ${WRKSRC} && ${INSTALL_OPTS} DESTDIR=${STAGEDIR} ./install-sh ${PREFIX}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCFILES1}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
.endfor
.for FILE in ${DOCFILES2}
	@${INSTALL_DATA} ${WRKSRC}/documentation/${FILE} ${DOCSDIR}/${FILE}
.endfor
.for DIR in stubs includes
	@${CP} -rf ${WRKSRC}/documentation/${DIR} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Docs installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
