# New ports collection makefile for:	dreampie
# Date created:			14 May 2010
# Whom:				Ju Pengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	dreampie
PORTVERSION=	1.1.1
CATEGORIES=	devel python
MASTER_SITES=	http://launchpadlibrarian.net/55587528/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	DreamPie is a Python shell which is designed to be reliable and fun

LICENSE=	GPLv3

USE_GNOME=	pygtk2 pygtksourceview
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		dreampie.1

pre-patch:
	@${REINPLACE_CMD} -e "s|share/man/man1|man/man1|" ${WRKSRC}/setup.py

.include <bsd.port.mk>
