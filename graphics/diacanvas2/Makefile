# ex:ts=8
# Ports collection makefile for:	diacanvas2
# Date created:			Feb 9, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	diacanvas2
PORTVERSION=	0.10.0
PORTREVISION=	0
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	diacanvas

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general drawing canvas from dia dialog editor

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_REINPLACE=	yes
USE_PYTHON=	2.2+
USE_GNOME=	gtk20 libgnomeprint libgnomeprintui gnomeprefix gnomehack \
		libartlgpl2 libgnomecanvas
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

PORTDOCS=	*
PLIST_FILES=	lib/libdiacanvas2.so lib/libdiacanvas2.so.0 \
		libdata/pkgconfig/diacanvas2.pc \
		share/locale/nl/LC_MESSAGES/diacanvas.mo \
		share/pygtk/2.0/defs/dia-boxed.defs \
		share/pygtk/2.0/defs/diacanvas.defs \
		share/pygtk/2.0/defs/diageometry.defs \
		share/pygtk/2.0/defs/diashape.defs \
		share/pygtk/2.0/defs/diaview.defs

post-install:
	@${FIND} ${PREFIX}/include/diacanvas -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm include/diacanvas' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/diacanvas -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/diacanvas -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
