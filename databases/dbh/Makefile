# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dbh
PORTVERSION=	5.0.22
CATEGORIES=	databases
MASTER_SITES=	SF
DISTNAME=	libdbh2-${PORTVERSION}

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Disk Based Hashtables

LICENSE=	GPLv3

CONFLICTS=	dbh-[0-4]*

USES=		libtool pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkglibdata
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	GTKDOC
GTKDOC_DESC=	Enable GTK html documentation

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTKDOC}
CONFIGURE_ARGS+=	--enable-gtk-doc-html
PLIST_SUB=	GTKDOC=""
.else
CONFIGURE_ARGS+=	--disable-gtk-doc-html
PLIST_SUB=	GTKDOC="@comment "
.endif

post-patch:
# Fix the build on big-endian architectures.
	@${REINPLACE_CMD} -e '/fractalidad/d' ${WRKSRC}/src/dbh_static.i
# Needed to remove gtk-doc installation.
.if empty(PORT_OPTIONS:MGTKDOC)
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS = src man\).*|\1|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
