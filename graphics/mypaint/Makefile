# New ports collection makefile for:	mypaint
# Date created:		12 June 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mypaint
PORTVERSION=	1.0.0
CATEGORIES=	graphics
MASTER_SITES=	http://download.gna.org/mypaint/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Fast painting/scribbling program

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:${PORTSDIR}/devel/py-protobuf
BUILD_DEPENDS:=	${RUN_DEPENDS} \
		swig:${PORTSDIR}/devel/swig13 \
		protoc:${PORTSDIR}/devel/protobuf

USE_BZIP2=	yes
USE_GNOME=	glib20 pygtk2
USE_PYTHON=	yes
USE_SCONS=	yes
SCONS_ARGS=	prefix="${PREFIX}"
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

SUB_FILES=	pkg-install

post-install:
# scons won't install icons if ${PREFIX}/share/icons already exists
	cd ${WRKSRC}/desktop && ${COPYTREE_SHARE} 'icons' ${PREFIX}/share
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
