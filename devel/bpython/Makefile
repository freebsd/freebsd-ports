# Created by: Yi-Jheng Lin <yzlin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bpython
PORTVERSION=	0.12
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://bpython-interpreter.org/releases/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fancy interface to the Python interpreter

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:${PORTSDIR}/textproc/py-sphinx
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:${PORTSDIR}/textproc/py-pygments

OPTIONS_DEFINE=	EXAMPLES NLS

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_BUILD_TARGET=	build bdist_egg

MAN1=		bpython.1
MAN5=		bpython-config.5
PORTEXAMPLES=	light.theme sample-config sample.theme

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USES+=		gettext
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/build\/man\/bpython/d; /data\/bpython.desktop/d' ${WRKSRC}/${PYSETUP}

post-install:
	${INSTALL_MAN} ${WRKSRC}/build/man/bpython.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/build/man/bpython-config.5 ${MANPREFIX}/man/man5/
	${INSTALL_DATA} ${WRKSRC}/data/bpython.desktop ${DESKTOPDIR}/
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}/
.endif
.if ${PORT_OPTIONS:MNLS}
.for lang in it_IT nl_NL
	${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES/
.endfor
.for lang in de es_ES it_IT nl_NL
	${INSTALL_DATA} ${WRKSRC}/bpython/translations/${lang}/LC_MESSAGES/bpython.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/
.endfor
.endif

.include <bsd.port.mk>
