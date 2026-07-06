PORTNAME=	greed
DISTVERSION=	5.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://catb.org/~esr/greed/
PKGNAMESUFFIX=	-game
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Text puzzle game with the aim of clearing the game field
WWW=		http://catb.org/~esr/greed/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cargo

CARGO_ENV=	RELEASE="${DISTVERSION}" \
		SCOREFILE="${SCOREFILE}"

SCOREFILE=	/var/games/greed.hs
PLIST_SUB=	SCOREFILE=${SCOREFILE}

OPTIONS_DEFINE=	DOCS
OPTIONS_UNSET=	DOCS

DOCS_PLIST_FILES=	share/man/man6/greed.6.gz
DOCS_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor

post-extract:
	${REINPLACE_CMD} -e 's|/usr/lib/games/greed.hs|${SCOREFILE}|g' ${WRKSRC}/greed.adoc

post-build-DOCS-on:
	@cd ${WRKSRC} && asciidoctor -D. -a nofooter -b manpage greed.adoc

post-install:
	@${MKDIR} ${STAGEDIR}${SCOREFILE:H}
	${TOUCH} ${STAGEDIR}${SCOREFILE}.sample

post-install-DOCS-on:
	${INSTALL_MAN} ${WRKSRC}/greed.6 ${STAGEDIR}${PREFIX}/share/man/man6/

.include <bsd.port.mk>
