PORTNAME=	tnef
PORTVERSION=	1.4.12
PORTREVISION=	2
CATEGORIES=	converters mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Unpack data in MS Outlook TNEF format
WWW=		https://tnef.sourceforge.net/

LICENSE=	GPLv2

USES=		cpe

CPE_VENDOR=	tnef_project

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PORTDOCS=	AUTHORS BUGS NEWS README.md THANKS
PLIST_FILES=	bin/tnef \
		share/man/man1/tnef.1.gz

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

# This target is intended to be run by the port maintainer.
x-test: build
.for dir in cmdline files
	@cd ${WRKSRC}/tests/${dir} && ${MAKE} check-TESTS
.endfor

.include <bsd.port.mk>
