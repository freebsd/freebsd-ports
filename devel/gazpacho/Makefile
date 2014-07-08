# Created by: Gustavo Fukao <gustavofukao@gmail.com>
# $FreeBSD$

PORTNAME=	gazpacho
PORTVERSION=	0.7.2
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gazpacho/0.7

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI builder for the GTK+ toolkit

RUN_DEPENDS=	${LOCALBASE}/bin/kiwi-i18n:${PORTSDIR}/x11-toolkits/py-kiwi
BUILD_DEPENDS=	${LOCALBASE}/bin/kiwi-i18n:${PORTSDIR}/x11-toolkits/py-kiwi

NO_BUILD=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USES=		gettext
DOCS=		AUTHORS ChangeLog CONTRIBUTORS COPYING README NEWS

post-patch:
	@${REINPLACE_CMD} -e 's|share/doc/gazpacho/examples|${EXAMPLESDIR}|g' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
. endfor

.include <bsd.port.mk>
