# New ports collection makefile for:	PostgreSQL Pgaccess
# Date created:		December 1st, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	pgaccess
PORTVERSION=	0.98.8
PORTREVISION=	1
CATEGORIES=	databases tcl83 tk83
MASTER_SITES=	http://www.pgaccess.org/download/
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@pingpong.net

LIB_DEPENDS=	pgtcl:${PORTSDIR}/databases/postgresql-tcltk

USE_REINPLACE=	yes

TCL_VERSION?=	8.4
PGACCESSDOCDIR=	${PREFIX}/share/doc/postgresql/pgaccess
PGACCESSDIR=	${PREFIX}/share/postgresql/pgaccess

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/bin,${PREFIX}/bin,g ; " ${WRKSRC}/lib/mainlib.tcl
	@${RM} ${WRKSRC}/lib/mainlib.tcl.bak

do-build:
.for file in pgaccess.tcl pgmonitor
	@ ${SED} -e "s,%%LOCALBASE%%,${LOCALBASE},g; \
		     s,%%TCL_VERSION%%,${TCL_VERSION},g; \
		     s,%%PREFIX%%,${PREFIX},g; \
		     s,%%PROGRAM%%,${file},g" \
		< ${FILESDIR}/run-tcl-file > ${WRKDIR}/${file:R}.sh
.endfor

do-install:
	@${MKDIR} ${PGACCESSDIR} ; \
	 cd ${WRKSRC} ;\
	 ${TAR} cf - `find * ! \( -path win32\* -o -path doc\* \)` | \
	 ( cd ${PGACCESSDIR}; ${TAR} xf - ) ; \
	 ${CHOWN} -R 0:0 ${PGACCESSDIR}
.for file in pgaccess pgmonitor
	${INSTALL_SCRIPT} ${WRKDIR}/${file}.sh ${PREFIX}/bin/${file}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PGACCESSDOCDIR} ; \
	 cd ${WRKSRC}/doc/html ;\
	 ${TAR} cf - * | \
	 ( cd ${PGACCESSDOCDIR}; ${TAR} xf - ) ; \
	 ${CHOWN} -R 0:0 ${PGACCESSDOCDIR}
.endif

.include <bsd.port.mk>
