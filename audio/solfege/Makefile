# ex:ts=8
# Ports collection makefile for:	solfege
# Date created:			Apr 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	solfege
PORTVERSION=	1.9.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free eartraining software

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig11 \
		${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2 \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		gm4:${PORTSDIR}/devel/m4 \
		msgfmt:${PORTSDIR}/devel/gettext-old
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_GNOME=	gtk20 libgtkhtml gnomehack gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${LOCALBASE}/bin/gm4
CONFIGURE_ARGS=	--enable-docbook-stylesheet=${LOCALBASE}/share/xsl/docbook/html/chunk.xsl --disable-oss-sound
USE_GMAKE=	yes

MAN1=	solfege.1

post-patch:
	@${REINPLACE_CMD} -e "s|[(]datadir[)]/locale|(prefix)/share/locale|g" ${WRKSRC}/po/Makefile
	@${GREP} -lR "/usr/bin/python2.2" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e "s,/usr/bin/python2.2,${SETENV} python,"
	@${REINPLACE_CMD} -e "s|python2.2|${PYTHON_CMD}|" ${WRKSRC}/online-docs/Rules.make
	@${REINPLACE_CMD} -e 's|\(python2.2 python2.1\)|${PYTHON_VERSION} \1|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
