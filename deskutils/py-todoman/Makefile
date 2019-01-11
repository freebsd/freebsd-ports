# $FreeBSD$

PORTNAME=		todoman
DISTVERSION=	3.5.0
CATEGORIES=		deskutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		andreas@bilke.org
COMMENT=		Simple CalDAV-based todo manager

LICENSE=		ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>1.12.0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atomicwrites>=0.1.7:devel/py-atomicwrites@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}click>=6.0:devel/py-click@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}click-log>=0.2.1:devel/py-click-log@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:devel/py-configobj@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}dateutil>=2.6:devel/py-dateutil@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}humanize>=0.5.1:devel/py-humanize@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}icalendar>=4.0.3:devel/py-icalendar@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}parsedatetime>=2.4:devel/py-parsedatetime@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}tabulate>=0.8.2:devel/py-tabulate@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}urwid>=2.0.1:devel/py-urwid@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}vdirsyncer>=0:deskutils/py-vdirsyncer@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}xdg>=0.25:devel/py-xdg@${PY_FLAVOR}

USES=			python:3.5+
USE_PYTHON=		autoplist distutils

NO_ARCH=		yes

PLIST_FILES=	share/zsh/site-functions/_todoman \
				${EXAMPLESDIR}/todoman.conf.sample

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/contrib/completion/zsh/_todo \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_todoman
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} todoman.conf.sample ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
