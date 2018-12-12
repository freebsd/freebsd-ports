# Created by: Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PORTNAME=	pgaccess
PORTVERSION=	1.00.20140902
PORTREVISION=	2
CATEGORIES=	databases tcl tk
MASTER_SITES=	http://bsdforge.com/projects/source/databases/pgaccess/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Powerful PostgreSQL database GUI administration tool and toolkit

LICENSE=	BSD4CLAUSE

RUN_DEPENDS=	${LOCALBASE}/lib/pgtcl/pkgIndex.tcl:databases/pgtcl

USES=		pgsql tk:85+ tar:xz

NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/postgresql/${PORTNAME}
PGACCESSDIR=	${PREFIX}/share/postgresql/${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/bin,${PREFIX}/bin,g ; " ${WRKSRC}/lib/mainlib.tcl
	@${RM} ${WRKSRC}/lib/mainlib.tcl.bak

do-build:
.for targetfile in pgaccess.tcl pgmonitor
	@ ${SED} -e "s,%%LOCALBASE%%,${LOCALBASE},g; \
		     s,%%WISH%%,${WISH},g; \
		     s,%%PREFIX%%,${PREFIX},g; \
		     s,%%PROGRAM%%,${targetfile},g" \
		< ${FILESDIR}/run-tcl-file > ${WRKDIR}/${targetfile:R}.sh
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PGACCESSDIR} ; \
	cd ${WRKSRC} ;\
	${TAR} cf - `${FIND} * ! \( -path win32\* -o -path doc\* \)` | \
	( cd ${STAGEDIR}${PGACCESSDIR}; ${TAR} xf - )
.for targetfile in pgaccess pgmonitor
	${INSTALL_SCRIPT} ${WRKDIR}/${targetfile}.sh ${STAGEDIR}${PREFIX}/bin/${targetfile}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ; \
	cd ${WRKSRC}/doc/html ;\
	${TAR} cf - * | \
	( cd ${STAGEDIR}${DOCSDIR}; ${TAR} xf - )

.include <bsd.port.mk>
