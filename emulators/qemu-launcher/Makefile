# $FreeBSD$

PORTNAME=	qemu-launcher
PORTVERSION=	1.7.4
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	http://download.gna.org/qemulaunch/1.7.x/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK front-end to Qemu

DEPRECATED=	Upstream is gone
EXPIRATION_DATE=	2018-05-31

RUN_DEPENDS=	p5-Gtk2>=0:x11-toolkits/p5-Gtk2 \
		p5-Glade2>=0:x11-toolkits/p5-Glade2 \
		p5-Locale-gettext>=0:devel/p5-Locale-gettext

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
USES=		gettext perl5

post-patch:
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},g' ${WRKSRC}/qemu-launcher.pl
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
