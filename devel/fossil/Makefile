# $FreeBSD$

PORTNAME=	fossil
PORTVERSION=	20130216000435
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel www
MASTER_SITES=	http://www.fossil-scm.org/download/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	DSCM with built-in wiki, http interface and server, tickets database

LICENSE=	BSD

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/fossil

HAS_CONFIGURE=	yes

OPTIONS_DEFINE=	JSON MARKDOWN STATIC
JSON_DESC=	JSON API support
MARKDOWN_DESC=	Markdown format support

JSON_CONFIGURE_ON=	--json
MARKDOWN_CONFIGURE_ON=	--markdown
STATIC_CONFIGURE_ON=	--static

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/fossil ${PREFIX}/bin/fossil

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
