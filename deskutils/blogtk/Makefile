# ex:ts=8
# Ports collection makefile for:	blogtk
# Date created:			Jul 30, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	blogtk
PORTVERSION=	1.0
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A client for Blogger, Movable Type, and other blogging systems

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_PYTHON=	2.3+
USE_GNOME=	pygtk2 pygnome2
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/BloGTK-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/shar,${PREFIX}/shar,' ${WRKSRC}/src/BloGTK.py

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${PYTHON_SITELIBDIR}/blogtk
	${INSTALL_SCRIPT} ${WRKSRC}/src/* ${PYTHON_SITELIBDIR}/blogtk
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/* ${DATADIR}
	@${LN} -fs ${PYTHON_SITELIBDIR}/blogtk/BloGTK.py ${PREFIX}/bin/blogtk
.for dir in ${PYTHON_SITELIBDIR}/blogtk ${DATADIR}
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} "@exec ln -fs %D/${PYTHON_SITELIBDIR:S,^${PREFIX}/,,}/blogtk/BloGTK.py %D/bin/blogtk" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rm -f %D/bin/blogtk 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.post.mk>
