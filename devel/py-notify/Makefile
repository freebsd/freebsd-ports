# $FreeBSD$

PORTNAME=	notify
PORTVERSION=	0.1.1
DISTVERSIONPREFIX=python-
PORTREVISION=	9
CATEGORIES=	devel python
MASTER_SITES=	http://www.galago-project.org/files/releases/source/notify-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A python bindings for libnotify

LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify

USE_BZIP2=	yes
USES=		gmake pkgconfig
USE_GNOME=	gnomehack pygtk2
USE_PYTHON=	-2.7
GNU_CONFIGURE=	yes

DOCS=		AUTHORS COPYING ChangeLog NEWS

NO_STAGE=	yes
post-extract:
	@${RM} ${WRKSRC}/src/pynotify.c

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
