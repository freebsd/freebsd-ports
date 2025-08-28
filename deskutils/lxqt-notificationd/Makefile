PORTNAME=	lxqt-notificationd
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	LXQt notification daemon
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+

USES=		cmake compiler:c++20-lang gettext kde:6 localbase:ldflags lxqt:2 qt:6 \
		perl5 pkgconfig tar:xz gnome xorg
USE_PERL5=	build
USE_QT=		base:run tools:build svg
USE_KDE=	layer-shell-qt windowsystem
USE_GNOME=	glib20
USE_XORG=	x11
USE_LXQT=	buildtools2 lxqt

.include <bsd.port.mk>
