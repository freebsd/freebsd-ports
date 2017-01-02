# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsystem
PORTVERSION=	0.3.1
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/4446/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	libSystem-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS core system library

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig ssl
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

BROKEN_FreeBSD_9=	fails to build

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
	gtkdoc-check:textproc/gtk-doc

post-patch:
	${REINPLACE_CMD} 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh
	${REINPLACE_CMD} 's|CFLAGS=|CFLAGS+=|' \
		${WRKSRC}/src/Makefile
	${REINPLACE_CMD} 's|CPPFLAGS=|CPPFLAGS+=|' \
		${WRKSRC}/src/Makefile
	${REINPLACE_CMD} 's|_fail "python.sh"|#_fail "python.sh"|' \
		${WRKSRC}/tests/tests.sh
	${REINPLACE_CMD} 's|-Wl,-pie||g' \
		${WRKSRC}/tools/Makefile \
		${WRKSRC}/tests/Makefile
	${REINPLACE_CMD} -e 's|$$(INSTALL)|#$${INSTALL}|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|$$(MKDIR) $$(DESTDIR)$$(PREFIX)/share/doc/| \
		#$$(MKDIR) $$(DESTDIR)$$(PREFIX)/share/doc/|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|./docbook.sh -P "$$(DESTDIR)$$(PREFIX)" -i -- "$$(OBJDIR)configctl.html"| \
		#./docbook.sh -P "$$(DESTDIR)$$(PREFIX)" -i -- "$$(OBJDIR)configctl.html"|' \
		${WRKSRC}/doc/Makefile

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|data doc include|data include|' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e '/^SUBDIRS/ s|doc||' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/configctl \
		${STAGEDIR}${PREFIX}/lib/libSystem.so.0.0

.include <bsd.port.mk>
