# New ports collection makefile for:   py-dbus
# Date Created:			25 July 2004
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/py-dbus/Makefile,v 1.10 2010/03/14 12:28:57 kwm Exp $
#

PORTNAME=	dbus
PORTVERSION=	0.83.1
PORTREVISION=	1
CATEGORIES=	devel gnome python
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for the D-BUS messaging system

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnometarget
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${PYTHON_INCLUDEDIR}"
CONFIGURE_ARGS=	--docdir=${DOCSDIR}

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/rst2html) && !defined(NOPORTDOCS)
PLIST_SUB+=	HTML=""
.else
CONFIGURE_ARGS+=--disable-html-docs
PLIST_SUB+=	HTML="@comment "
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|HEADERS install-dist_docDATA|HEADERS|g ; \
		s|PYTHON install-nodist_docDATA|PYTHON|g' \
			${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR} && \
		${INSTALL_DATA} ${WRKSRC}/examples/*.py ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
