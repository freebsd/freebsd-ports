# New ports collection makefile for:	gresolver
# Date created:			23 Oct 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		gresolver
PORTVERSION=		0.0.3
PORTREVISION=		2
CATEGORIES=		dns
MASTER_SITES=		http://jodrell.net/files/gresolver/

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		A graphical DNS query tool using GTK+

USE_GCC=	4.0

RUN_DEPENDS=		${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext \
			${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
			${SITE_PERL}/${PERL_ARCH}/Gtk2/GladeXML.pm:${PORTSDIR}/x11-toolkits/p5-Glade2 \
			${SITE_PERL}/Net/IPv6Addr.pm:${PORTSDIR}/net-mgmt/p5-Net-IPv6Addr

USE_X_PREFIX=		yes
NO_BUILD=		yes
USE_REINPLACE=		yes

.include <bsd.port.pre.mk>

post-patch:
	@${SED} -e \
		's|share/pixmaps|share/gnome/pixmaps| ; \
		 s|@PREFIX@|${PREFIX}|' \
		${WRKSRC}/gresolver.pl > ${WRKSRC}/gresolver
	@${REINPLACE_CMD} -e 's|Icon=gresolver|&.png|' ${WRKSRC}/gresolver.desktop

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gresolver ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/gresolver.desktop ${PREFIX}/share/gnome/applications
	${MKDIR} ${PREFIX}/share/gnome/pixmaps
	${INSTALL_DATA} ${WRKSRC}/gresolver.png ${PREFIX}/share/gnome/pixmaps
	${MKDIR} ${PREFIX}/share/gresolver
	${INSTALL_DATA} ${WRKSRC}/gresolver.glade ${PREFIX}/share/gresolver

.include <bsd.port.post.mk>
