# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dbh
PORTVERSION=	5.0.19
CATEGORIES=	databases
MASTER_SITES=	SF
DISTNAME=	libdbh2-${PORTVERSION}

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Disk Based Hashtables

LICENSE=	GPLv3

CONFLICTS=	dbh-[0-4]*

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool pkgconfig
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GTKDOC
GTKDOC_DESC=	Enable GTK html documentation

.for a in ia64 powerpc sparc64
BROKEN_${a}=	Does not compile on ia64, powerpc, or sparc64
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTKDOC}
CONFIGURE_ARGS+=	--enable-gtk-doc-html
PLIST_SUB=	GTKDOC=""
.else
CONFIGURE_ARGS+=	--disable-gtk-doc-html
PLIST_SUB=	GTKDOC="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^pkgconfigdir.*|pkgconfigdir = $${PREFIX}/libdata/pkgconfig|' ${WRKSRC}/Makefile.in
# Needed to remove gtk-doc installation.
.if empty(PORT_OPTIONS:MGTKDOC)
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS = src man\).*|\1|' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
