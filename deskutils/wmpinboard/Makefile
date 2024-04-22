PORTNAME=	wmpinboard
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	deskutils afterstep windowmaker
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	t.kempka@web.de
COMMENT=	Post-it notes for the WindowMaker dock or AfterStep Wharf

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig

USES=		gmake xorg
USE_XORG=	xpm
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

PLIST_FILES=	bin/wmpinboard \
		share/man/man1/wmpinboard.1.gz

.include <bsd.port.mk>
