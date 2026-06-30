PORTNAME=	python-tools
DISTVERSION=	${PYTHON_DISTVERSION}
PORTREVISION=	1
CATEGORIES=	lang python devel
MASTER_SITES=	PYTHON/ftp/python/${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Python-${DISTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Supplementary tools for the Python language

LICENSE=	PSFL

USES=		python shebangfix tar:xz
USE_PYTHON=	concurrent flavors

DISTINFO_FILE=	${.CURDIR}/../python${PYTHON_SUFFIX}/distinfo
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${PYLIB_FILES:C|^|bin/|} ${SCRIPT_FILES:C|^|bin/|}

SHEBANG_FILES=	${PYLIB_FILES:C|.*|Lib/&.py|} ${SCRIPT_FILES:C|.*|Tools/scripts/&.py|}

PYLIB_FILES=	tabnanny timeit

PORTSCOUT=	ignore:1

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31200
SCRIPT_FILES=	byteyears copytime crlf dutree lfcr ptags untabify
.endif

do-install:
.for fname in ${PYLIB_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/Lib/${fname}.py ${STAGEDIR}${PREFIX}/bin/${fname}
.endfor
.for fname in ${SCRIPT_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/Tools/scripts/${fname}.py ${STAGEDIR}${PREFIX}/bin/${fname}
.endfor

.include <bsd.port.post.mk>
