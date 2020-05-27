# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	libtpl
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Library for serializing C data

LICENSE=	GPLv3 MIT
LICENSE_COMB=	multi

OPTIONS_DEFINE=	DOCS

USES=		libtool
USE_GITHUB=	yes
GH_ACCOUNT=	waitman
GH_TAGNAME=	8fa17e5

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libtpl.a lib/libtpl.so \
		lib/libtpl.so.0 lib/libtpl.so.0.0.0 \
		include/tpl.h

PORTDOCS=	ChangeLog.txt examples.txt userguide.txt compiling.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
