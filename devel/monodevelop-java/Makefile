# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	monodevelop-java
PORTVERSION=	2.8.8.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	MonoDevelop Java/IKVM language support

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop

BROKEN=		does not build

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		gettext
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GNOME=	gtksharp20

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/JavaBinding.make

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
