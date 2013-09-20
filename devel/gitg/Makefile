# Created by: kipz <somicide@gmail.com>
# $FreeBSD$

PORTNAME=	gitg
PORTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	devel deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GTK-based git repository viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	git>=1.7.0.2:${PORTSDIR}/devel/git

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gconf2 gtk20 gtksourceview2 gnomehack
USES=		gettext gmake pkgconfig

INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	gitg.schemas

MAN1=		gitg.1

NO_STAGE=	yes
.include <bsd.port.mk>
