# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	libtpl
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Tpl is a library for serializing C data

OPTIONS_DEFINE=	DOCS

LICENSE=	BSD

USES=		libtool tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	waitman
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	8fa17e5

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libtpl.a lib/libtpl.so \
		lib/libtpl.so.0 lib/libtpl.so.0.0.0 \
		include/tpl.h

PORTDOCS=	ChangeLog.txt examples.txt userguide.txt compiling.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
