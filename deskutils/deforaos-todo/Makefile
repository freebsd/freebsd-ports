# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	todo
PORTVERSION=	0.2.1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.defora.org/os/download/download/4429/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Todo-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS desktop todo list

LICENSE=	GPLv3

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop
BUILD_DEPENDS=	${LOCALBASE}/include/Desktop/Mailer/plugin.h:mail/deforaos-mailer

USES=		desktop-file-utils pkgconfig
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}

MAKE_ENV=	MANDIR=${STAGEDIR}${MANPREFIX}/man

CONFLICTS_INSTALL=	devtodo todo

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|= data doc|= data|' \
		${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|po src tools|src tools|' \
		${WRKSRC}/Makefile

post-patch:
	${REINPLACE_CMD} 's|-Wl,-pie||g' \
		${WRKSRC}/tools/Makefile \
		${WRKSRC}/src/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/todo \
		${STAGEDIR}${PREFIX}/lib/Mailer/plugins/todo.so

.include <bsd.port.mk>
