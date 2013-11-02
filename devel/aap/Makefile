# Created by: Bram Moolenaar <bram@a-a-p.org>
# $FreeBSD$

PORTNAME=	aap
PORTVERSION=	1.093
CATEGORIES=	devel
MASTER_SITES=	SF/a-a-p/Aap/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Build tool alternative to make with internet access and CVS support

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_ZIP=	yes
USE_PYTHON=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.options.mk>

do-install:
	@cd ${WRKSRC} && ${PYTHON_CMD} ./aap PREFIX="${STAGEDIR}/${PREFIX}" \
		FULLDOCS=no install
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
	    -d ${PREFIX}/lib/aap/Exec-${PORTVERSION}/ -f ${STAGEDIR}${PREFIX}/lib/aap/Exec-${PORTVERSION}
	@${LN} -sf ../lib/aap/Exec-${PORTVERSION}/aap \
		${STAGEDIR}${PREFIX}/bin/aap
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} exec.pdf \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}/html
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html \
		${STAGEDIR}${DOCSDIR}/html)
	@${LN} -sf ../../../${DOCSDIR_REL} \
		${STAGEDIR}${PREFIX}/lib/aap/Exec-${PORTVERSION}/doc

test: install
	cd ${WRKSRC}; ${PREFIX}/bin/aap

.include <bsd.port.mk>
