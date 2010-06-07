# New ports collection makefile for:	codeblocks
# Date created:				November, 15th 2005
# Whom:					Matthias Sund <m.sund@arcor.de>
#
# $FreeBSD$
#

PORTNAME=		codeblocks
PORTVERSION=		10.05
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-${PORTVERSION}-1debian-src

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Open source, cross-platform, free C/C++ IDE

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme

LICENSE_COMB=	multi
LICENSE=	GPLv3 LGPL3

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

post-extract:
	(cd ${WRKDIR} && ${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} src/${PORTNAME}_${PORTVERSION}-1.tar.gz ${EXTRACT_AFTER_ARGS})

.include <bsd.port.mk>
