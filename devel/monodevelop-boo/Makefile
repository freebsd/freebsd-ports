# New ports collection makefile for:	monodevelop-boo
# Date created:		2008-03-02
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	monodevelop-boo
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	MonoDevelop Boo language support

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop \
		${LOCALBASE}/libdata/pkgconfig/gtksourceview-sharp-2.0.pc:${PORTSDIR}/x11-toolkits/gtksourceview-sharp \
		booc:${PORTSDIR}/lang/boo
RUN_DEPENDS=	${BUILD_DEPENDS}

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GNOME=	gtksharp20
USE_BZIP2=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/BooBinding.make ${WRKSRC}/BooShell/Makefile
	@${REINPLACE_CMD} -e 's|@prefix@/lib/pkgconfig|@prefix@/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.include

.include <bsd.port.mk>
