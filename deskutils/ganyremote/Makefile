# New ports collection makefile for:	ganyremote
# Date created:				08 November 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	ganyremote
PORTVERSION=	5.10
PORTREVISION=	4
CATEGORIES=	deskutils comms gnome
MASTER_SITES=	SF/anyremote/${PORTNAME}/${PORTVERSION}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	GNOME frontend for anyRemote

RUN_DEPENDS=	anyremote:${PORTSDIR}/comms/anyremote

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GNOME=	pygtk2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	AUTHORS COPYING README ChangeLog

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|usepybluez = True|usepybluez = False|' \
		-e '/initVerify()$$/d' ${WRKSRC}/${PORTNAME}
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/doc\/${PORTNAME}/d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
