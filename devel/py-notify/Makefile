# New ports collection makefile for:	py-notify
# Date created:				03 December 2006
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	notify
PORTVERSION=	0.1.1
DISTVERSIONPREFIX=python-
PORTREVISION=	5
CATEGORIES=	devel python
MASTER_SITES=	http://www.galago-project.org/files/releases/source/notify-python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A python bindings for libnotify

LIB_DEPENDS=	notify.1:${PORTSDIR}/devel/libnotify

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget pygtk2
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

DOCS=		AUTHORS COPYING ChangeLog NEWS

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
