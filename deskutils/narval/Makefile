# ex:ts=8
# Ports collection Makefile for:	narval
# Date created:			Jan 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	narval
PORTVERSION=	1.2.a.1
PORTREVISION=	1
CATEGORIES=	deskutils python
MASTER_SITES=	ftp://ftp.logilab.org/pub/narval/ \
		http://www.logilab.org/ftp/pub/narval/
DISTNAME=	Narval-${PORTVERSION:S/.a.1/a1/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network Assistant Reasoning with a Validating Agent Language

RUN_DEPENDS=	${PYXML} \
		${PYTHON_SITELIBDIR}/${XMLDIR}/xpath/__init__.py:${PORTSDIR}/textproc/py-4suite \
		${PYTHON_SITELIBDIR}/gtk-1.2/GDK.py:${PORTSDIR}/x11-toolkits/py-gtk \
		${PYTHON_SITELIBDIR}/xmlrpclib.py:${PORTSDIR}/net/py-xmlrpclib \
		${PYTHON_SITELIBDIR}/logilab/xmltools/XmlTree.py:${PORTSDIR}/textproc/py-xmltools

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
DOCFILES=	ANNOUNCE.en ANNOUNCE.fr CHANGELOG CONTRIBUTORS README.WIN32 README.UNIX faq.en.xml ../README ../license.txt

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} == "python1.5" || ${PYTHON_VERSION} == "python1.6"
XMLDIR=		xml
.else
XMLDIR=		_xmlplus
.endif

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/share,${PREFIX}/share,g" ${WRKSRC}/conf/narval.conf

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/docs
	@${MKDIR} ${DOCSDIR}/docs/NEP
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}/docs
	@${INSTALL_DATA} ${WRKSRC}/doc/NEP/* ${DOCSDIR}/docs/NEP/
.endif

.include <bsd.port.post.mk>
