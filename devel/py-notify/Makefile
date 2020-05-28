# $FreeBSD$

PORTNAME=	notify
PORTVERSION=	0.1.1
DISTVERSIONPREFIX=python-
PORTREVISION=	12
CATEGORIES=	devel python
MASTER_SITES=	http://www.galago-project.org/files/releases/source/notify-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for libnotify

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS=	libnotify.so:devel/libnotify

USES=		gmake gnome libtool:keepla pathfix pkgconfig python:2.7 \
		tar:bzip2
USE_GNOME=	pygtk2
USE_PYTHON=	flavors
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes

DOCS=		AUTHORS COPYING ChangeLog NEWS

post-extract:
	@${RM} ${WRKSRC}/src/pynotify.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
