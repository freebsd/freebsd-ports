# ex:ts=8
# Ports collection makefile for:	cgkit
# Date created:			Apr 15, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cgkit
PORTVERSION=	2.0.0a7
PORTREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/a/alpha/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Computer Graphics Kit

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost-jam \
		scons:${PORTSDIR}/devel/scons
LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs \
		boost_python.4:${PORTSDIR}/devel/boost-python-libs

USE_GL=		yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	2.0.0alpha7

.if defined(INSTALL_CGKIT_LIGHT)
PLIST_SUB+=	CGKIT_LIGHT="@comment "
.else
PLIST_SUB+=	CGKIT_LIGHT=""
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/OpenGL:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_SITELIBDIR}/numarray/__init__.py:${PORTSDIR}/math/py-numarray \
		${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/protocols/__init__.py:${PORTSDIR}/devel/py-protocols \
		${PKGNAMEPREFIX}serial>=2.2:${PORTSDIR}/comms/py-serial \
		aqsis:${PORTSDIR}/graphics/aqsis
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042 && ${ARCH} == "amd64"
BROKEN=	does not compile
.endif

.if defined(WITH_LIB3DS)
LIB_DEPENDS+=	3ds-1.3:${PORTSDIR}/graphics/lib3ds
.endif

DOS2UNIX_FILES=	viewer.py render.py utilities/postbake.py

pre-everything::
.if !defined(WITH_LIB3DS)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_LIB3DS if you want to be able to import 3ds files"
	@${ECHO_MSG}
.endif

.if !defined(INSTALL_CGKIT_LIGHT)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define INSTALL_CGKIT_LIGHT if you do not want to install any external dependencies"
	@${ECHO_MSG}
.endif

post-extract:
	@cd ${WRKSRC}; \
	for FILE in $($$DOS2UNIX_FILES); do \
		${MV} $${FILE} $${FILE}.dos; \
		${CAT} $${FILE}.dos | ${TR} -d '\r'> $${FILE}; \
		${RM} $${FILE}.dos; \
	done;

pre-configure:
	@${CP} ${FILESDIR}/cpp_config.cfg ${WRKSRC}/supportlib; \
	${CP} ${FILESDIR}/config.cfg ${WRKSRC};
.if defined(WITH_LIB3DS)
	@${REINPLACE_CMD} -e "s/^#//1" ${WRKSRC}/config.cfg;
.endif
.if defined(INSTALL_CGKIT_LIGHT)
	@${ECHO} "INSTALL_CGKIT_LIGHT = True" >> ${WRKSRC}/config.cfg;
.endif
	@${REINPLACE_CMD} -e "/%%LOCALBASE%%/s//${LOCALBASE:S/\//\\\//g}/g" \
	     ${WRKSRC}/supportlib/cpp_config.cfg ${WRKSRC}/config.cfg; \
	cd ${WRKSRC}/supportlib; \
	scons

.include <bsd.port.post.mk>
