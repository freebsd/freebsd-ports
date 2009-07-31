# New ports collection makefile for:	codeblocks
# Date created:				November, 15th 2005
# Whom:					Matthias Sund <m.sund@arcor.de>
#
# $FreeBSD$
#

PORTNAME=		codeblocks
PORTVERSION=		8.02
PORTREVISION=	3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Open source, cross-platform, free C/C++ IDE

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme

USE_BZIP2=	yes
USE_WX=		2.8
WANT_UNICODE=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_ARGS+=	--with-wx-config=${WX_CONFIG} --with-contrib-plugins=all
MAN1=	cb_console_runner.1 cb_share_config.1 codeblocks.1 codesnippets.1

.include <bsd.port.mk>
