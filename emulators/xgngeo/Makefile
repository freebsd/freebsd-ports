# New ports collection makefile for:	xgngeo
# Date created:		2006-03-02
# Whom:			Jose Alonso Cardenas Marquez <acardebas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	xgngeo
PORTVERSION=	16
PORTEPOCH=	1
CATEGORIES=	emulators games
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME:S/xg/XG/}-${PORTVERSION}
DIST_SUBDIR=	gngeo

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Fronted (GUI) for gngeo

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygtk.pth:${PORTSDIR}/x11-toolkits/py-gtk2 \
		gngeo:${PORTSDIR}/emulators/gngeo

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_PYDISTUTILS=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_PSYCO=	yes
.endif

.if !defined(WITHOUT_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/data/py/configfile.py

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/xgngeo-doc.pdf ${WRKSRC}/doc/xgngeo-doc.txt  ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
