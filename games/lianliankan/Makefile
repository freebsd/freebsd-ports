# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	lianliankan
DISTVERSION=	2.3beta1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/llk-linux/llk-linux-source/${DISTVERSION}
DISTNAME=	llk_linux-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Tile matching game

LICENSE=	GPLv2

USES=		pkgconfig
USE_GNOME=	gtk20 esound
USE_AUTOTOOLS=	aclocal automake autoconf libtool

AUTOMAKE_ARGS=	--add-missing --copy
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DATADIR=	${PREFIX}/share/llk_linux
DOCSDIR=	${PREFIX}/share/doc/llk_linux

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|po||' \
		${WRKSRC}/Makefile.am
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/lianliankan.desktop ${PREFIX}/share/applications

.include <bsd.port.mk>
