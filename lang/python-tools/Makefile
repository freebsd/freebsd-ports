PORTNAME=	python-tools
DISTVERSION=	${PYTHON_DISTVERSION}
PORTREVISION=	1
CATEGORIES=	lang python devel
MASTER_SITES=	PYTHON/ftp/python/${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Python-${DISTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Supplementary tools for the Python language

LICENSE=	PSFL

PORTSCOUT=	ignore:1

USES=		python shebangfix tar:xz
USE_PYTHON=	flavors concurrent
NO_BUILD=	yes
NO_ARCH=	yes

DIST_SUBDIR=	python
DISTINFO_FILE=	${.CURDIR}/../python${PYTHON_SUFFIX}/distinfo
WRKSRC_SUBDIR=		Tools/scripts

SCRIPT_FILES=	byteyears copytime crlf dutree \
		lfcr ptags untabify
PYLIB_FILES=	tabnanny timeit
PLIST_FILES=	${SCRIPT_FILES:C|^|bin/|} ${PYLIB_FILES:C|^|bin/|}

SHEBANG_FILES=	${SCRIPT_FILES:C|$|.py|} \
		${PYLIB_FILES:C|.*|../../Lib/&.py|}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
SCRIPT_FILES+=	checkpyc
.endif

do-install:
.for fname in ${SCRIPT_FILES}
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/${fname}.py \
		${STAGEDIR}${PREFIX}/bin/${fname}
.endfor
.for fname in ${PYLIB_FILES}
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/../../Lib/${fname}.py \
		${STAGEDIR}${PREFIX}/bin/${fname}
.endfor

.include <bsd.port.post.mk>
