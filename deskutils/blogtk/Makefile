# ex:ts=8
# Ports collection makefile for:	blogtk
# Date created:			Jul 30, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	blogtk
PORTVERSION=	1.1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A client for Blogger, Movable Type, and other blogging systems

WRKSRC=		${WRKDIR}/BloGTK-${PORTVERSION}

USE_BZIP2=	yes
USE_GNOME=	pygnomeextras
USE_PYTHON=	2.3+
NO_BUILD=	yes

post-patch:
	@${FIND} ${WRKSRC}/src -name "*.py" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|g ; \
		 s|gtk\.FALSE|False|g ; \
		 s|gtk\.TRUE|True|g'

do-install:
	@${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/blogtk
	${INSTALL_SCRIPT} ${WRKSRC}/src/*.py ${PYTHONPREFIX_SITELIBDIR}/blogtk
	@${LN} -fs ${PYTHONPREFIX_SITELIBDIR}/blogtk/BloGTK.py ${PREFIX}/bin/blogtk
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.glade ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.gladep ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.png ${DATADIR}

.include <bsd.port.mk>
