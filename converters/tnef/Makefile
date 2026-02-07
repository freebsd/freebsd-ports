PORTNAME=	tnef
DISTVERSION=	1.4.18
CATEGORIES=	converters mail

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Unpack data in MS Outlook TNEF format
WWW=		https://tnef.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf cpe
CPE_VENDOR=	tnef_project
USE_GITHUB=	yes
GH_ACCOUNT=	verdammelt

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/tnef \
		share/man/man1/tnef.1.gz
PORTDOCS=	AUTHORS BUGS NEWS README.md THANKS

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

# This target is intended to be run by the port maintainer.
x-test: build
.for dir in cmdline files
	@cd ${WRKSRC}/tests/${dir} && ${MAKE} check-TESTS
.endfor

.include <bsd.port.mk>
