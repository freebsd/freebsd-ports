# New ports collection makefile for:	nano
# Date created:				12 June 2000
# Whom:				Philippe Lefebvre <nemesis@balistik.net>
#
# $FreeBSD$
#

PORTNAME=	nano
PORTVERSION=	1.0.1
CATEGORIES=	editors
MASTER_SITES=	http://www.nano-editor.org/dist/ \
		http://www.asty.org/nano/dist/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nemesis@balistik.net

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

.if defined(LITE)
CONFIGURE_ARGS+=	--disable-tabcomp --enable-tiny --disable-speller \
		--disable-justify --disable-nls --disable-browser --disable-help
PLIST=		${PKGDIR}/pkg-plist.nonls
.endif

MAN1=		nano.1

.include <bsd.port.mk>
