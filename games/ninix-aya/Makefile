# Created by: UMENO Takashi
# $FreeBSD$

PORTNAME=	ninix-aya
PORTVERSION=	4.4
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SFJP/${PORTNAME}/58500

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop mascot program compatible with "Ukagaka"

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYNUMPY}

NO_ARCH=	yes

USES=		gmake python:2.7 tar:tgz
USE_GNOME=	pygtk2
USE_GSTREAMER=	python

DOCSDIR=	${PREFIX}/share/doc/ninix

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

do-build:
	@(cd ${WRKSRC}/bin && ${SED} -e \
		's|@python|${PYTHON_CMD}| ; \
		 s|@libdir|${PREFIX}/libexec/ninix|' ninix.in > ninix)
.if ${PORT_OPTIONS:MNLS}
.for i in ja zh_TW
	(cd ${WRKSRC}/locale && ${LOCALBASE}/bin/msgfmt -o ${i}.mo ${i}.po)
.endfor
.endif

do-install:
	(cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} ninix \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/ninix
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/libexec/ninix)
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX}/libexec/ninix -f libexec/ninix)
.if ${PORT_OPTIONS:MNLS}
.for i in ja zh_TW
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES
	(cd ${WRKSRC}/locale && ${INSTALL_DATA} ${i}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES/ninix.mo)
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ChangeLog README README.ninix TODO.ninix KNOWN_ISSUES
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor
.for i in extension.txt kawari.txt saori.txt
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
