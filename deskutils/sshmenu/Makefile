# New ports collection makefile for:	sshmenu
# Date created:		2010-10-03
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sshmenu
PORTVERSION=	3.18
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	GNOME panel applet for managing ssh connections

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/panelapplet2.so:${PORTSDIR}/x11-toolkits/ruby-panelapplet \
		${RUBY_SITEARCHLIBDIR}/gconf2.so:${PORTSDIR}/devel/ruby-gconf2 \
		${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/License.txt
USE_RUBY=	yes
NO_BUILD=	yes
INSTALLS_ICONS=	yes

MAN1=		sshmenu.1

.include <bsd.port.pre.mk>

post-extract:
	${REINPLACE_CMD} -e 's|#!/usr/bin/ruby|#!${RUBY_WITHOUT_SUFFIX}|' ${WRKSRC}/bin/sshmenu
	${REINPLACE_CMD} -e 's|#!/usr/bin/ruby|#!${RUBY_WITHOUT_SUFFIX}|' ${WRKSRC}/bin/sshmenu-gnome
	${REINPLACE_CMD} -e 's|#!/usr/bin/ruby|#!${RUBY_WITHOUT_SUFFIX}|' ${WRKSRC}/sshmenu-applet
	${REINPLACE_CMD} -e 's|/usr/lib/gnome-panel|${LOCALBASE}/libexec|' ${WRKSRC}/sshmenu-applet.server
	${REINPLACE_CMD} -e 's|/usr/bin/ssh-askpass|${LOCALBASE}/bin/ssh-askpass|' ${WRKSRC}/lib/sshmenu.rb

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lib/sshmenu.rb ${RUBY_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/lib/gnome-sshmenu.rb ${RUBY_SITELIBDIR}
	${INSTALL} ${WRKSRC}/sshmenu-applet.server ${PREFIX}/libdata/bonobo/servers
	${INSTALL} ${WRKSRC}/sshmenu-applet ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/sshmenu.1 ${MAN1PREFIX}/man/man1
	${INSTALL} ${WRKSRC}/gnome-sshmenu-applet.png ${PREFIX}/share/icons/gnome/48x48/apps
	${INSTALL} ${WRKSRC}/bin/sshmenu ${PREFIX}/bin
	${INSTALL} ${WRKSRC}/bin/sshmenu-gnome ${PREFIX}/bin

.include <bsd.port.post.mk>
