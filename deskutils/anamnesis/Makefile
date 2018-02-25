# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	anamnesis
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Clipboard manager that stores all clipboard history

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gtk2>0:x11-toolkits/py-gtk2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR}

USES=		python:2.7 shebangfix
PORTDOCS=	ChangeLog README
OPTIONS_DEFINE=	DOCS
NO_ARCH=	yes
SHEBANG_FILES=	source/anamnesis.py

post-patch:
	@${REINPLACE_CMD} 's|cfg_files.reverse()|cfg_files += [os.path.join("'${PREFIX}/etc/'",cfg_filename)]; cfg_files.reverse()|' \
		${WRKSRC}/source/config.py
do-build:
	@(cd ${WRKSRC} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${WRKSRC} -f ${WRKSRC} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${WRKSRC} -f ${WRKSRC})
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/anamnesis
.for f in anamnesis browser config clipboard clipboard_gtk clipboard_gtk_xclip daemon db db_sqlite3fts
	${INSTALL_DATA} ${WRKSRC}/source/${f}.py ${STAGEDIR}${PREFIX}/share/anamnesis
	${INSTALL_DATA} ${WRKSRC}/source/${f}.pyc ${STAGEDIR}${PREFIX}/share/anamnesis
	${INSTALL_DATA} ${WRKSRC}/source/${f}.pyo ${STAGEDIR}${PREFIX}/share/anamnesis
.endfor
	${LN} -sf ../share/anamnesis/anamnesis.py ${STAGEDIR}${PREFIX}/bin/anamnesis
	${INSTALL_DATA} ${WRKSRC}/anamnesis.cfg ${STAGEDIR}${PREFIX}/etc/anamnesis.cfg.sample
	${INSTALL_MAN} ${WRKSRC}/man/anamnesis.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
