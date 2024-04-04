PORTNAME=	flexemu
DISTVERSIONPREFIX=	V
DISTVERSION=	3.20
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	MC6809 emulator running FLEX operating system
WWW=		https://flexemu.neocities.org/

LICENSE=	GPLv2

USES=		desktop-file-utils gl libtool qt:5 shared-mime-info xorg
USE_GITHUB=	yes
GH_ACCOUNT=	aladur
GH_TUPLE=	google:googletest:e1a38bc3:googletest/googletest
USE_GL=		gl
USE_QT=		buildtools:build core dbus gui network printsupport \
		qmake:build widgets x11extras
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/rcvflex
	@${RM} ${STAGEDIR}${PREFIX}/bin/send2flx
	@${RM} ${STAGEDIR}${PREFIX}/bin/testdaa

.include <bsd.port.post.mk>
