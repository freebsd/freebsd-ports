# New ports collection makefile for:	yank
# Date created:				28 November 1999
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yank
PORTVERSION=	0.2.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	yank

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple notekeeper and todo-list manager for GNOME

BUILD_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell

BROKEN=		Incomplete pkg-plist

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gal gconf gnomehack gnomeprefix gnomeprint
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB=	VERSION="${PORTVERSION}"

GCONF_SCHEMAS=	yank.schemas

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|_la_LDFLAGS =|& -avoid-version|g'

.include <bsd.port.mk>
