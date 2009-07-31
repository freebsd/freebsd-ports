# New ports collection makefile for:	gbirthday
# Date created:				01 January 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	gbirthday
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A birthday reminder for Evolution contacts

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PYTHON_RUN=	yes
USE_GNOME=	pygtk2 evolutiondataserver

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/${PORTNAME}|${DATADIR}|g' \
		${WRKSRC}/${PORTNAME}.py ${WRKSRC}/${PORTNAME}.desktop
	@${RM} ${WRKSRC}/languages/*.orig

do-install:
.for dir in pics languages
	@${MKDIR} ${DATADIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/* ${DATADIR}/${dir}/
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${DATADIR}
	${LN} -fs ${DATADIR}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications

.include <bsd.port.mk>
