# New ports collection makefile for:	qcad
# Version required:	1.3.3
# Date created:		10 Dec 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	qcad_source
PKGNAME=	qcad-1.3.3
CATEGORIES=	cad
MASTER_SITES=	http://www.ultraviolet.org/qcad/

MAINTAINER=	andrews@technologist.com

USE_XLIB=	yes
MAKEFILE=	makefile
MAKE_ENV=	CC="${CXX}"
USE_QT2=	yes

QCADDIR=	${PREFIX}/lib/qcad
QCADDOCDIR=	${PREFIX}/share/doc/qcad
QCADSAMPLEDIR=	${PREFIX}/share/examples/qcad

do-install:
	@${MKDIR} ${QCADDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/qcad ${QCADDIR}
.for dir in cur fonts hatches messages xpm
	${CP} -R ${WRKSRC}/${dir} ${QCADDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${QCADDOCDIR}
	${CP} -R ${WRKSRC}/doc/* ${QCADDOCDIR}
	@${LN} -sf ${QCADDOCDIR} ${QCADDIR}/doc
.endif
	@${MKDIR} ${QCADSAMPLEDIR}
	${CP} -R ${WRKSRC}/examples/* ${QCADSAMPLEDIR}
	${SED} -e "s;%%PREFIX%%;${PREFIX};g" \
		< ${FILESDIR}/qcad.in > ${PREFIX}/bin/qcad
	${CHMOD} +x ${PREFIX}/bin/qcad

.include <bsd.port.mk>
