# ex:ts=8
# Ports collection makefile for:	ziarc
# Date created:			Jan 11, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ziarc
PORTVERSION=	20020729 # date of the tarball
CATEGORIES=	cad
MASTER_SITES=	http://www.procoders.net/downloads/
DISTNAME=	ziarc_src

DEPRECATED=	"no longer available from author's site"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ZiaRC is a Resistor Calculator

BUILD_DEPENDS=	${PYNUMERIC}
RUN_DEPENDS=	${PYNUMERIC}

BROKEN=		Checksum mismatch

USE_ZIP=	yes
USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
NO_WRKSUBDIR=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|g" ${WRKSRC}/rnetgui.py

do-install:
	${CAT} ${FILESDIR}/ziarc | \
		${SED} -e "s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|" > \
		${PREFIX}/bin/ziarc
	@${CHMOD} +x ${PREFIX}/bin/ziarc
	@${MKDIR} ${PYTHON_SITELIBDIR}/ziarc
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${PYTHON_SITELIBDIR}/ziarc
	@${RM} -f ${PYTHON_SITELIBDIR}/ziarc/setup.py
	@${MKDIR} ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.png ${DATADIR}/icons

.include <bsd.port.mk>
