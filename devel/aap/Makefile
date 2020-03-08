# Created by: Bram Moolenaar <bram@a-a-p.org>
# $FreeBSD$

PORTNAME=	aap
PORTVERSION=	1.094
CATEGORIES=	devel
MASTER_SITES=	SF/a-a-p

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Build tool alternative to make with internet access and CVS support

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

OPTIONS_DEFINE=	DOCS

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USES=		python:2.7 shebangfix zip
PLIST_SUB=	PORTVERSION="${PORTVERSION}"
NO_ARCH=	yes
SHEBANG_FILES=	Filetype.py Main.py PkgInstall.py PrintProfile.py RootShell.py aap.py aap

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
