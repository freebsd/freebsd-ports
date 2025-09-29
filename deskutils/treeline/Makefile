PORTNAME=	treeline
PORTVERSION=	3.2.1
CATEGORIES=	deskutils python
MASTER_SITES=	https://github.com/doug-101/TreeLine/releases/download/v${PORTVERSION}/ \
		SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Structured information storage program
WWW=		https://treeline.bellz.org

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

USES=		python pyqt:6 shebangfix
USE_PYQT=	pyqt6

SHEBANG_FILES=	source/treeline.py

CONFIGURE_ARGS=	-b ${STAGEDIR} -p ${PREFIX} -d ${DOCSDIR} -i ${DATADIR}/icons
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/TreeLine

OPTIONS_DEFINE=		DOCS NLS
SPELL_DESC=		Spell check support
OPTIONS_SINGLE=		SPELL
OPTIONS_SINGLE_SPELL=	ASPELL HUNSPELL ISPELL
OPTIONS_DEFAULT=	ASPELL
OPTIONS_SUB=		yes

ASPELL_BUILD_DEPENDS=	aspell:textproc/aspell
ASPELL_RUN_DEPENDS=	aspell:textproc/aspell
ASPELL_VARS=		SPELL_ENGINE=aspell

HUNSPELL_BUILD_DEPENDS=	hunspell:textproc/hunspell
HUNSPELL_RUN_DEPENDS=	hunspell:textproc/hunspell
HUNSPELL_VARS=		SPELL_ENGINE=hunspell

ISPELL_BUILD_DEPENDS=	ispell:textproc/aspell-ispell
ISPELL_RUN_DEPENDS=	ispell:textproc/aspell-ispell
ISPELL_VARS=		SPELL_ENGINE=ispell

NLS_CONFIGURE_OFF=	-s

post-patch:
	@${REINPLACE_CMD} -e 's|%%SPELL_ENGINE%%|${SPELL_ENGINE}|' \
		${WRKSRC}/install.py \
		${WRKSRC}/source/spellcheck.py

do-install:
	(cd ${WRKSRC} && ${PYTHON_CMD} install.py ${CONFIGURE_ARGS})
	(cd ${STAGEDIR}${PREFIX} && \
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${DATADIR} -f ${DATADIR_REL})
	(cd ${STAGEDIR}${DATADIR} && ${RM} *.bak *.orig *.pro *.spec)
	(cd ${STAGEDIR}${DOCSDIR} && ${RM} INSTALL LICENSE)

.include <bsd.port.mk>
