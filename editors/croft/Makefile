PORTNAME=	croft
# No upstream releases; version is the Cargo.toml version plus the
# pinned commit's date (see CROFT_COMMIT below).
DISTVERSION=	0.1.271.20260602
CATEGORIES=	editors
MASTER_SITES=	https://codeberg.org/vitali87/${PORTNAME}/archive/${CROFT_COMMIT}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	VS Code style three pane workspace inside your terminal
WWW=		https://croft.sh/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

# No upstream releases yet; pin a main-branch commit (2026-06-02).
CROFT_COMMIT=	cf3354eff596acc957fd3afa5133c20b9376d39f

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/croft

.include <bsd.port.mk>
