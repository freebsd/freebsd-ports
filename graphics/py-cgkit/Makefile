# ex:ts=8
# Ports collection makefile for:	cgkit
# Date created:			Apr 15, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cgkit
PORTVERSION=	2.0.0a
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}lpha4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Computer Graphics Kit

BUILD_DEPENDS=	bjam:${PORTSDIR}/devel/boost-python scons:${PORTSDIR}/devel/scons
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenGL:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_SITELIBDIR}/numarray/__init__.py:${PORTSDIR}/math/py-numarray \
		${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/protocols/__init__.py:${PORTSDIR}/devel/py-protocols \
		aqsis:${PORTSDIR}/graphics/aqsis

USE_XLIB=	yes
USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 502126 )
BROKEN=	"does not compile"
.endif

.if defined(WITH_LIB3DS)
LIB_DEPENDS+=	3ds.1:${PORTSDIR}/graphics/lib3ds
.endif

DOS2UNIX_FILES=	viewer.py render.py utilities/postbake.py

pre-everything::
.if !defined(WITH_LIB3DS)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_LIB3DS if you want to be able to import 3ds files"
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
	@${REINPLACE_CMD} -e "/%%LOCALBASE%%/s//${LOCALBASE:S/\//\\\//g}/g" \
	    -e "/%%X11BASE%%/s//${X11BASE:S/\//\\\//g}/g" ${WRKSRC}/supportlib/cpp_config.cfg ${WRKSRC}/config.cfg; \
	cd ${WRKSRC}/supportlib; \
	scons

.include <bsd.port.post.mk>
