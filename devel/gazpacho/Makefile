# New ports collection makefile for:	gazpacho
# Date created:		2006-09-08
# Whom:			Gustavo Fukao <gustavofukao@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gazpacho
PORTVERSION=	0.6.6
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.acc.umu.se/pub/GNOME/sources/gazpacho/0.6/

MAINTAINER=	gustavofukao@gmail.com
COMMENT=	GUI builder for the GTK+ toolkit

RUN_DEPENDS=	${LOCALBASE}/bin/kiwi-i18n:${PORTSDIR}/x11-toolkits/py-kiwi
BUILD_DEPENDS=	${LOCALBASE}/bin/kiwi-i18n:${PORTSDIR}/x11-toolkits/py-kiwi

NO_BUILD=	yes

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GETTEXT=	yes

PORTDOCS=	AUTHORS ChangeLog CONTRIBUTORS COPYING README NEWS

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|share/doc/gazpacho/examples|${EXAMPLESDIR}|g' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
