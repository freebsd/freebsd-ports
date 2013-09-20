# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	libtpl
PORTVERSION=	1.6
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Tpl is a library for serializing C data

LICENSE=	BSD

USE_BZIP2=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	waitman
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	8fa17e5

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libtpl.la lib/libtpl.a \
		lib/libtpl.so lib/libtpl.so.0 \
		include/tpl.h

PORTDOCS=	ChangeLog.txt examples.txt userguide.txt compiling.txt

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
