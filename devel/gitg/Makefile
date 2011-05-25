# New ports collection makefile for:	gitg
# Date created:		2010-03-19
# Whom:			kipz <somicide@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gitg
PORTVERSION=	0.0.8
CATEGORIES=	devel deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GTK-based git repository viewer

RUN_DEPENDS=	git>=1.7.0.2:${PORTSDIR}/devel/git

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gconf2 gtk20 gtksourceview2 gnomehack
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

INSTALLS_ICONS=	yes
GCONF_SCHEMAS=	gitg.schemas

MAN1=		gitg.1

.include <bsd.port.mk>
