# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	monodevelop-database
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	MonoDevelop database support

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/monodevelop.pc:${PORTSDIR}/devel/monodevelop

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gnomehack gtksharp20

post-patch:
	@${REINPLACE_CMD} -e 's|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
