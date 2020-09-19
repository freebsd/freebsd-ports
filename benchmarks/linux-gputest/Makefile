# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gputest
PORTVERSION=	0.7.0
CATEGORIES=	benchmarks linux
MASTER_SITES=	http://vault.101011010.xyz/distfiles/ \
		http://freebsd.nsu.ru/distfiles/ LOCAL/danfe
		# http://www.ozone3d.net/gputest/dl/ (original
		# upstream URL, but they ask not to hotlink)
DISTNAME=	GpuTest_Linux_x64_${PORTVERSION}
PKGNAMEPREFIX=	linux-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GPU stress test and OpenGL benchmark

LICENSE=	GEEKS3D
LICENSE_NAME=	Geeks3D End-User License Agreement
LICENSE_FILE=	${WRKSRC}/EULA.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	amd64

PATCH_DEPENDS=	p5-Sys-Mmap>0:devel/p5-Sys-Mmap

USES=		linux perl5 zip
USE_LINUX=	dri libglvnd xorglibs
USE_PERL5=	patch
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS GUI
OPTIONS_DEFAULT=	GUI
OPTIONS_SUB=	yes

GUI_DESC=	Install Python/Tkinter-based GUI launcher
GUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}
GUI_USES=	python:run

post-patch:
	@${REINPLACE_CMD} -e '1s,bash,sh,' ${WRKSRC}/start_*.sh
	@${RM} ${WRKSRC}/data/.DS_Store
	@cd ${WRKSRC} && ${PERL} ${FILESDIR}/apply-binary-patch.pl < \
		${FILESDIR}/fix-logfile-path.crk

# We cannot just embed shebang line in the patch because 210:fix-shebang
# happens before 500:do-patch :(
post-patch-GUI-on:
	@${REINPLACE_CMD} -e '1 { x; s,^,#!${PYTHON_CMD},; G; }' \
		${WRKSRC}/gputest_gui.py

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} data \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/*.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/GpuTest \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/start_*.sh \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/_geeks3d_gputest_scores.csv \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${PRINTF} '#!/bin/sh\n\ncd ${PREFIX}/lib/${PORTNAME} || exit\
		1\n\nexec ./GpuTest "$$@"\n' > \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-GUI-on:
	${INSTALL_SCRIPT} ${WRKSRC}/gputest_gui.py ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
