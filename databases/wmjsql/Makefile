# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmjsql
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	databases windowmaker
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MySQL server status displaying dockapp

LICENSE=	GPLv2 # (or later)

WRKSRC=		${WRKDIR}/${PORTNAME}/src

USES=		gmake
USE_MYSQL=	yes
USE_XORG=	xpm
ALL_TARGET=	clean all
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/X11 -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/mysql -L${LOCALBASE}/lib

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

post-patch:
.for i in Makefile jDockApp/Makefile xutils/Makefile
	@${REINPLACE_CMD} -e \
		'/^INCDIR/s|=.*|= $${CPPFLAGS}| ; \
		 /^LIBDIR/s|=.*|= $${LDFLAGS}| ; \
		 /^CC/d ; \
		 /^CFLAGS/d ; \
		 s| make | $$(MAKE) | ; \
		 s|-D$$(shell echo `uname -s`)||' ${WRKSRC}/${i}
.endfor
.for i in wmjsql.jet ../README
	@${REINPLACE_CMD} -E 's|\.wmjsql([^r])|\.wmjsqlrc\1|' \
		${WRKSRC}/${i}
.endfor

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/.. && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
