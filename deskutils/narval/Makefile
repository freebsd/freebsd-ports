# Created by: ijliao
# $FreeBSD$

PORTNAME=	narval
PORTVERSION=	2.0.2
PORTREVISION=	7
CATEGORIES=	deskutils python
MASTER_SITES=	LOGILAB

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network Assistant Reasoning with a Validating Agent Language

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xmlrpclib.py:${PORTSDIR}/net/py-xmlrpclib \
		${PYTHON_SITELIBDIR}/logilab/xmltools/XmlTree.py:${PORTSDIR}/textproc/py-xmltools \
		${PYTHON_SITELIBDIR}/mx/DateTime/mxDateTime/__init__.py:${PORTSDIR}/lang/py-mx-base

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USES=		twisted
USE_GNOME=	pygtk2

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} -e 's|(.share/doc/narval., .doc.)||' ${WRKSRC}/__pkginfo__.py
.endif

before-install:
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' ${WRKSRC}/conf/narval.conf.bak

post-install:
	@${INSTALL_DATA} ${WRKSRC}/conf/narval.conf ${PREFIX}/etc/narval/narval.conf.bak

.include <bsd.port.post.mk>
