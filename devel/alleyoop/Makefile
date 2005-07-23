# New ports collection makefile for:	Alleyoop
# Date created:		Fri Jun 17 23:52:44 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	alleyoop
PORTVERSION=	0.8.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A graphical front-end to Valgrind memory checker

BUILD_DEPENDS=	${LOCALBASE}/lib/libbfd.a:${PORTSDIR}/devel/libbfd \
		${GNULIBIBERTY_WRKSRC}/libiberty.a:${PORTSDIR}/devel/gnulibiberty:build \
		${LOCALBASE}/include/libelf/elf_repl.h:${PORTSDIR}/devel/libelf
RUN_DEPENDS=	valgrind:${PORTSDIR}/devel/valgrind

BROKEN=		Incorrect pkg-plist
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

USE_GMAKE=	yes
USE_X_PREFIX=	yex
USE_GETTEXT=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehier \
		gconf2 \
		glib20 \
		gtk20 \
		libglade2 \
		libgnome \
		libgnomeui \
		pango

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${GNULIBIBERTY_WRKSRC} \
			${LDFLAGS} -L${LOCALBASE}/lib"

GCONF_SCHEMAS=	${PORTNAME}.schemas

.include <bsd.port.pre.mk>

GNULIBIBERTY=	${PORTSDIR}/devel/gnulibiberty
GNULIBIBERTY_WRKSRC!=	cd ${PORTSDIR}/devel/gnulibiberty && ${MAKE} -V WRKSRC

.include <bsd.port.post.mk>
