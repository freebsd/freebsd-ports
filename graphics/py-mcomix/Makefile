# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mcomix
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/MComix-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GTK2 comic book viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Old, uses EOLed python27
EXPIRATION_DATE=	2020-03-01

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow6>=5.2.0:graphics/py-pillow6@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gnome python:2.7 tar:bzip2
USE_GNOME=	pygtk2
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
