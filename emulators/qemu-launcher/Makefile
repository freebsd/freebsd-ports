# New ports collection makefile for:	qemu-launcher
# Date created:				22 December 2005
# Whom:					Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	qemu-launcher
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://emeitner.f2o.org/debian/
DISTNAME=	${PORTNAME}_${PORTVERSION}-1

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	A GTK front-end to Qemu

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2/GladeXML/:${PORTSDIR}/x11-toolkits/p5-Glade2 \
		${SITE_PERL}/${PERL_ARCH}/Gnome2.pm:${PORTSDIR}/x11-toolkits/p5-Gnome2 \
		${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext

WRKSRC=		${WRKDIR}/trunk

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=	qemu-launcher.1

post-patch:
	@${REINPLACE_CMD} -e 's,usr,usr/local,g' ${WRKSRC}/qemu-launcher

# XXX: Currently not installing qemu-launcher.desktop or qemu-launcher.xpm
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qemu-launcher ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/qemu-launcher.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/qemu-launcher/glade
.for file in diskimages.glade qemulauncher.glade qemulauncher.png
	${INSTALL_DATA} ${WRKSRC}/glade/${file} ${PREFIX}/share/qemu-launcher/glade
.endfor

.include <bsd.port.mk>
