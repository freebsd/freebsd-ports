# ex:ts=8
# Ports collection makefile for:	solfege
# Date created:			Apr 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	solfege
PORTVERSION=	2.0.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free eartraining software

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext-old \
		gm4:${PORTSDIR}/devel/m4 \
		swig:${PORTSDIR}/devel/swig11 \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix libgtkhtml
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${LOCALBASE}/bin/gm4
CONFIGURE_ARGS=	--disable-oss-sound \
		--enable-docbook-stylesheet=${LOCALBASE}/share/xsl/docbook/html/chunk.xsl
PLIST_SUB=	VERSION=${PORTVERSION}

MAN1=		solfege.1

post-patch:
	@${GREP} -lR "/usr/bin/python2.2" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/bin/python2.2|${SETENV} python|g'
	@${REINPLACE_CMD} -e 's|share/solfege|share/gnome/solfege|g' \
		${WRKSRC}/run-solfege.py.in
	@${REINPLACE_CMD} -e 's|(datadir)/locale|(prefix)/share/locale|g' \
		${WRKSRC}/po/Makefile

.include <bsd.port.mk>
