# Created by: ijliao
# $FreeBSD$

PORTNAME=	gettext-lint
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check the validity and consistency of PO and POT files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NO_BUILD=	yes

USES=		gettext:run shebangfix
SHEBANG_FILES=	src/POFileEquiv.in src/POFileGlossary.in
USE_PYTHON_RUN=	yes

post-patch:
.for i in POFileChecker POFileClean POFileConsistency POFileEquiv POFileFill \
	POFileGlossary POFileSpell POFileStatus
	cd ${WRKSRC}/src && ${SED} -e 's|@PYTHON@|${PYTHON_CMD}|g ; \
		 s|@prefix@/share/@PACKAGE@|${PYTHON_SITELIBDIR}/${PORTNAME}|g' ${i}.in > ${i}
.endfor

do-install:
.for i in POFileChecker POFileClean POFileConsistency POFileEquiv POFileFill \
	POFileGlossary POFileSpell POFileStatus
	${INSTALL_SCRIPT} ${WRKSRC}/src/${i} ${STAGEDIR}${PREFIX}/bin/${i}
	${INSTALL_MAN} ${WRKSRC}/doc/${i}.1 ${STAGEDIR}${MANPREFIX}/man/man1/${i}.1
.endfor
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/*.py \
		${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/etc/*.css ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/etc/*.xsl ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
