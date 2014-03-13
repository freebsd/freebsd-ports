# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/py-dbus/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	dbus
PORTVERSION=	1.1.1
CATEGORIES=	devel gnome python
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for the D-BUS messaging system

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib

USES=		gettext pathfix pkgconfig gmake
USE_PYTHON=	2
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${PYTHON_INCLUDEDIR}
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--disable-api-docs

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=HTMLDOCS
HTMLDOCS_DESC=	build html documentation

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTMLDOCS}
BUILD_DEPENDS+=	rst2html:${PORTSDIR}/textproc/py-docutils
PLIST_SUB+=	HTML=""
.else
CONFIGURE_ARGS+=--disable-html-docs
PLIST_SUB+=	HTML="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|HEADERS install-dist_docDATA|HEADERS|g ; \
		s|PYTHON install-nodist_docDATA|PYTHON|g' \
			${WRKSRC}/Makefile.in
.endif

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} && \
		${INSTALL_DATA} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
