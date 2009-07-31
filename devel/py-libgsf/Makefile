# New ports collection makefile for:	py-libgsf
# Date created:				Oct 3, 2006
# Whom:					Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/py-libgsf/Makefile,v 1.1 2006/10/04 00:34:55 ahze Exp $

PORTREVISION=	2
CATEGORIES=	devel gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python wrapper for libgsf

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

MASTERDIR=	${.CURDIR}/../libgsf
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	gnomehack libgsf_gnome gnomevfs2 ltverhack intlhack pygtk2
USE_PYTHON=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc/gsf \
		--disable-gtk-doc --with-bz2 --with-gnome --with-python
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=
GSF_SLAVE=	yes

.include "${MASTERDIR}/Makefile"
