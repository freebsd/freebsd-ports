# Created by: Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PORTNAME=	pgaccess
PORTVERSION=	0.99.0.20040219
PORTREVISION=	3
CATEGORIES=	databases tcl tk
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	A powerful GUI PostgreSQL database administration tool and toolkit

BUILD_DEPENDS+=	${RUN_DEPENDS}
RUN_DEPENDS=	${LOCALBASE}/lib/pgtcl/pkgIndex.tcl:${PORTSDIR}/databases/pgtcl

USE_PGSQL=	server:extract

TCLVERSION?=	8.4
DOCSDIR=	${PREFIX}/share/doc/postgresql/${PORTNAME}
PGACCESSDIR=	${PREFIX}/share/postgresql/${PORTNAME}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,/usr/bin,${PREFIX}/bin,g ; " ${WRKSRC}/lib/mainlib.tcl
	@${RM} ${WRKSRC}/lib/mainlib.tcl.bak

do-build:
.for targetfile in pgaccess.tcl pgmonitor
	@ ${SED} -e "s,%%LOCALBASE%%,${LOCALBASE},g; \
		     s,%%TCL_VERSION%%,${TCLVERSION},g; \
		     s,%%PREFIX%%,${PREFIX},g; \
		     s,%%PROGRAM%%,${targetfile},g" \
		< ${FILESDIR}/run-tcl-file > ${WRKDIR}/${targetfile:R}.sh
.endfor

do-install:
	@${MKDIR} ${PGACCESSDIR} ; \
	 cd ${WRKSRC} ;\
	 ${TAR} cf - `${FIND} * ! \( -path win32\* -o -path doc\* \)` | \
	 ( cd ${PGACCESSDIR}; ${TAR} xf - ) ; \
	 ${CHOWN} -R 0:0 ${PGACCESSDIR}
.for targetfile in pgaccess pgmonitor
	${INSTALL_SCRIPT} ${WRKDIR}/${targetfile}.sh ${PREFIX}/bin/${targetfile}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ; \
	 cd ${WRKSRC}/doc/html ;\
	 ${TAR} cf - * | \
	 ( cd ${DOCSDIR}; ${TAR} xf - ) ; \
	 ${CHOWN} -R 0:0 ${DOCSDIR}
.endif

.include <bsd.port.mk>
