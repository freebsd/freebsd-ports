# ex:ts=8
# Ports collection Makefile for:	narval
# Date created:			Jan 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	narval
PORTVERSION=	1.1
CATEGORIES=	deskutils python
MASTER_SITES=	ftp://ftp.logilab.org/pub/narval/ \
		http://www.logilab.org/ftp/pub/narval/
DISTNAME=	Narval-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} == "python1.5" || ${PYTHON_VERSION} == "python1.6"
XMLDIR=		xml
.else
XMLDIR=		_xmlplus
.endif

RUN_DEPENDS=	${PYXML} \
		${PYTHON_SITELIBDIR}/${XMLDIR}/xpath/__init__.py:${PORTSDIR}/textproc/py-4suite \
		${PYTHON_SITELIBDIR}/GDK.py:${PORTSDIR}/x11-toolkits/py-gtk \
		${PYTHON_SITELIBDIR}/xmlrpclib.py:${PORTSDIR}/net/py-xmlrpclib \
		${PYTHON_SITELIBDIR}/logilab/xmltools/XmlTree.py:${PORTSDIR}/textproc/py-xmltools

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

post-patch:
	@${PERL} -pi -e "s,/etc,${PREFIX}/etc,g ; \
		s,base/doc,base/share/doc,g" ${WRKSRC}/setup.py
	@${PERL} -pi -e "s,/etc,${PREFIX}/etc,g" ${WRKSRC}/narval/config.py
	@${PERL} -pi -e "s,/usr/share,${PREFIX}/share,g" ${WRKSRC}/conf/narval.conf

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.post.mk>
