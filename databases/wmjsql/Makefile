# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmjsql
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	databases windowmaker
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MySQL server status displaying dockapp

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_MYSQL=	yes
USE_XORG=	xpm
ALL_TARGET=	clean all
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src

CPPFLAGS+=	-I${LOCALBASE}/include/X11 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/mysql -L${LOCALBASE}/lib

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
.for i in Makefile jDockApp/Makefile xutils/Makefile
	@${REINPLACE_CMD} -e \
		'/^INCDIR/s|=.*|= $${CPPFLAGS}| ; \
		 /^LIBDIR/s|=.*|= $${LDFLAGS}| ; \
		 /^CC/d ; \
		 /^CFLAGS/d ; \
		 s| make | $$(MAKE) | ; \
		 s|-D$$(shell echo `uname -s`)||' ${BUILD_WRKSRC}/${i}
.endfor
.for i in wmjsql.jet ../README
	@${REINPLACE_CMD} -E 's|\.wmjsql([^r])|\.wmjsqlrc\1|' \
		${BUILD_WRKSRC}/${i}
.endfor

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
