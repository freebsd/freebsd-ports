# Created by: Matthias Sund <m.sund@arcor.de>
# $FreeBSD$

PORTNAME=	codeblocks
PORTVERSION=	12.11
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/Sources/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}-1

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Open source, cross-platform, free C/C++ IDE

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	boost_system:${PORTSDIR}/devel/boost-libs \
		hunspell:${PORTSDIR}/textproc/hunspell \
		rsync:${PORTSDIR}/net/librsync
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

USES=		pkgconfig
USE_FAM=	yes
USE_WX=		2.8
WANT_UNICODE=	yes
USE_GNOME=	gnomehack desktopfileutils
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}release8629

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=	--with-wx-config=${WX_CONFIG} --with-contrib-plugins=all

MAN1=	cb_console_runner.1 cb_share_config.1 codeblocks.1 codesnippets.1

.include <bsd.port.mk>
