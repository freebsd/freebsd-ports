# New ports collection makefile for:	dia
# Date created:        21 December 1999
# Whom:                saper@system.pl
#
# $FreeBSD$
#

PORTNAME=	dia
PORTVERSION=	0.94
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.94
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT=	Diagram creation program, similar to Visio

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomehack gnomeprefix libxslt libartlgpl2 intlhack
WANT_GNOME=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl" \
		LOCALBASE="${LOCALBASE}"

MAN1=		dia.1

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
USE_GNOME+=	pygtk2
CONFIGURE_ARGS=	--with-python
PLIST_SUB=	PYTHON:=""
.else
PLIST_SUB=	PYTHON:="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=		libgnomeui
CONFIGURE_ARGS+=	--enable-gnome --enable-bonobo
PKGNAMESUFFIX=		-gnome
.else
USE_REINPLACE=	yes
post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} -e \
		's,\(^GTK_LIBS.*\),\1 ${PTHREAD_LIBS}, ; \
		 s,\(^GTK_CFLAGS = \),\1 ${PTHREAD_CFLAGS} ,'
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dia.xpm ${PREFIX}/share/gnome/dia/

.include <bsd.port.post.mk>
