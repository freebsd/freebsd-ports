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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJSON}
CONFIGURE_ARGS+=	--json
.endif

.if ${PORT_OPTIONS:MMARKDOWN}
CONFIGURE_ARGS+=	--markdown
.endif

.if ${PORT_OPTIONS:MSTATIC}
CONFIGURE_ARGS+=	--static
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/fossil ${PREFIX}/bin/fossil

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
