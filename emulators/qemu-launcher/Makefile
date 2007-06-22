# New ports collection makefile for:	qemu-launcher
# Date created:				22 December 2005
# Whom:					Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	qemu-launcher
PORTVERSION=	1.7.4
CATEGORIES=	emulators
MASTER_SITES=	http://download.gna.org/qemulaunch/1.7.x/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	wxs@atarininja.org
COMMENT=	A GTK front-end to Qemu

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Gtk2/GladeXML/:${PORTSDIR}/x11-toolkits/p5-Glade2 \
		${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PERL5=	yes
NO_BUILD=	yes
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes

MAN1=	qemu-launcher.1

post-patch:
	@${REINPLACE_CMD} -e 's,usr,usr/local,g' ${WRKSRC}/qemu-launcher.pl

.include <bsd.port.mk>
