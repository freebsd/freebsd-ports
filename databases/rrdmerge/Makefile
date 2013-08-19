# Created by: sobomax
# $FreeBSD$

PORTNAME=	rrdmerge
PORTVERSION=	0.0.1
#PORTREVISION=	0
CATEGORIES=	databases
MASTER_SITES=	http://download.sippysoft.com/thirdparty/
DISTNAME=	${PORTNAME}-${GITREVISION}
EXTRACT_SUFX=	.tbz2

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	An utility to merge existing RRD data from backups into new RRD files

RUN_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool

GITREVISION=	b05d69bfac64
USE_BZIP2=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rrdmerge ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/rrdmergetree ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/README.rst ${PREFIX}/share/doc/${PORTNAME}

.include <bsd.port.mk>
